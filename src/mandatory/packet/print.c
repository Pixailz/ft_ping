/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:20:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/16 23:08:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

#define PKT_3 "  %01x  "
#define PKT_4 "   %01x   "
#define PKT_8 "      %02x       "
#define PKT_13 "          %04x           "
#define PKT_16 "             %04x              "
#define PKT_24 "                    %06x                     "
#define PKT_32 "                           %08x                            "

static const char	*g_bin_bar = \
" 0                   1                   2                   3\n" \
" 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1\n";

static const char	*g_iphdr_fmt = \
"Internet Header Format\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_4 "|" PKT_4 "|" PKT_8 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_16 "|" PKT_3 "|" PKT_13 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_8 "|" PKT_8 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_32 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_32 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_24 "|" PKT_8 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

static const char	*g_pkt_icmp_header = \
"ICMP: Echo or Echo Reply Message\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_8 "|" PKT_8 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_16 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

void	packet_print_iphdr(t_iphdr *pkt)
{
	dprintf(DEBUG_FD, g_iphdr_fmt,
		pkt->version, pkt->ihl, pkt->tos, pkt->total_len, \
		pkt->identification, \
		(pkt->fragment_off & IPHDR_M_FLAGS) >> 13, \
		pkt->fragment_off & IPHDR_M_FRAG_OFF, \
		pkt->ttl, pkt->protocol, pkt->checksum, \
		pkt->src_addr, \
		pkt->dst_addr, \
		pkt->options, pkt->padding);
}

void	packet_print_icmphdr(t_icmphdr_echo *pkt)
{
	dprintf(DEBUG_FD, g_pkt_icmp_header, pkt->type, pkt->code, pkt->checksum,
		pkt->identifier, pkt->sequence);
}

void	packet_print_icmpdata(void *data)
{
	struct timeval	*tv;

	tv = (struct timeval *)(data + 4);
	dprintf(DEBUG_FD, "tv.sec %ld\n", tv->tv_sec);
	dprintf(DEBUG_FD, "tv.usec %ld\n", tv->tv_usec);
}

void	packet_print(void *pkt)
{
	dprintf(DEBUG_FD, "Dissect of packet\n%s", g_bin_bar);
	packet_print_iphdr(pkt);
	packet_print_icmphdr(pkt + LEN_HDR_IP);
	packet_print_icmpdata(pkt + LEN_HDR_IP + LEN_HDR_ICMP_ECHO);
}

void	packet_print_raw(char *pkt)
{
	t_size	i;

	i = 0;
	dprintf(DEBUG_FD, "Raw packet (%d)\n", PACKET_SIZE);
	while (i < PACKET_SIZE)
	{
		dprintf(DEBUG_FD, "%02X", (unsigned char)pkt[i]);
		i++;
		if (i % 16 == 0)
			dprintf(DEBUG_FD, "\n");
		else if (i % 2 == 0)
			dprintf(DEBUG_FD, " ");
	}
	dprintf(DEBUG_FD, "\n");
}
