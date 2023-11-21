/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:14:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/21 04:33:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

void	ft_fill_hdr_icmp(t_icmphdr_echo *packet)
{
	t_conf	*conf;

	conf = get_conf();
	packet->type = ICMP_ECHO;
	packet->code = 0;
	packet->checksum = 0;
	packet->identifier = ft_htons(conf->id_icmp);
	packet->sequence = ft_htons(0);
	packet->checksum = ft_checksum((void *)packet, \
						LEN_HDR_ICMP_ECHO + LEN_ICMP_ECHO_PAY + PADDING);
	dprintf(DEBUG_FD, "icmphdr_echo: checksum 0x%04x\n", packet->checksum);
	dprintf(DEBUG_FD, "icmphdr_echo: packet len %ld\n", sizeof(*packet));
}

static void	fill_random_data(void *buffer, t_size size)
{
	ft_memset(buffer, 42, size);
}

void	ft_hdr_icmp_seq_inc(void)
{
	static t_conf			*conf = FT_NULL;
	static t_icmphdr_echo	*pkt = FT_NULL;

	if (!conf)
	{
		conf = get_conf();
		pkt = (t_icmphdr_echo *)(conf->packet + LEN_HDR_IP);
	}
	conf->sequence++;
	pkt->sequence = conf->sequence;
	pkt->checksum = 0;
	pkt->checksum = ft_checksum((void *)pkt, \
						LEN_HDR_ICMP_ECHO + LEN_ICMP_ECHO_PAY + PADDING);
}

void	ft_hdr_icmp_echo_fill(void *packet)
{
	if (gettimeofday(packet + LEN_HDR_ICMP_ECHO, NULL) == -1)
		dprintf(2, "Failed to get time of day\n");
	fill_random_data(packet + LEN_HDR_ICMP_ECHO + PADDING, LEN_ICMP_ECHO_PAY);
	ft_fill_hdr_icmp(packet);
}
