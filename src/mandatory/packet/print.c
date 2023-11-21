/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:20:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/21 03:55:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

# if FT_PING_USE_IP_OPTS == 1
void	packet_print_iphdr(t_iphdr *pkt)
{
	dprintf(DEBUG_FD, FMT_IPHDR, \
		pkt->version, pkt->ihl, pkt->tos, pkt->total_len, \
		pkt->identification, \
		(pkt->fragment_off & IPHDR_M_FLAGS) >> 13, \
		pkt->fragment_off & IPHDR_M_FRAG_OFF, \
		pkt->ttl, pkt->protocol, pkt->checksum, \
		pkt->src_addr, \
		pkt->dst_addr, \
		pkt->options, pkt->padding);
}
# else
void	packet_print_iphdr(t_iphdr *pkt)
{
	dprintf(DEBUG_FD, FMT_IPHDR, \
		pkt->version, pkt->ihl, pkt->tos, pkt->total_len, \
		pkt->identification, \
		(pkt->fragment_off & IPHDR_M_FLAGS) >> 13, \
		pkt->fragment_off & IPHDR_M_FRAG_OFF, \
		pkt->ttl, pkt->protocol, pkt->checksum, \
		pkt->src_addr, \
		pkt->dst_addr);
}
# endif // FT_PING_USE_IP_OPTS == 1

void	packet_print_icmphdr(t_icmphdr_echo *pkt)
{
	dprintf(DEBUG_FD, FMT_ICMPHDR_ECHO, pkt->type, pkt->code, pkt->checksum,
		pkt->identifier, pkt->sequence);
}

void	packet_print_icmpdata(void *data)
{
	struct timeval	*tv;
	char			payload[LEN_ICMP_ECHO_PAY];

	tv = (struct timeval *)(data);
	ft_memcpy(payload, data + PADDING, LEN_ICMP_ECHO_PAY);
	payload[LEN_ICMP_ECHO_PAY] = 0;
	dprintf(DEBUG_FD, "timestamp (ms) %ld\n", \
											(tv->tv_sec * A_SEC) + tv->tv_usec);
	dprintf(DEBUG_FD, "payload \n");
	packet_print_raw(payload, LEN_ICMP_ECHO_PAY);
}

void	packet_print(void *pkt)
{
	dprintf(DEBUG_FD, "%s", FMT_BIN_BAR);
	packet_print_iphdr(pkt);
	packet_print_icmphdr(pkt + LEN_HDR_IP);
	packet_print_icmpdata(pkt + LEN_HDR_IP + LEN_HDR_ICMP_ECHO);
}

void	packet_print_raw(char *pkt, t_size size)
{
	t_size	i;

	i = 0;
	while (i < size)
	{
		dprintf(DEBUG_FD, "%02X", (unsigned char)pkt[i]);
		i++;
		if (i % 16 == 0)
			dprintf(DEBUG_FD, "\n");
		else if (i % 2 == 0)
			dprintf(DEBUG_FD, "   ");
		else if (i % 1 == 0)
			dprintf(DEBUG_FD, " ");
	}
	dprintf(DEBUG_FD, "\n");
}
