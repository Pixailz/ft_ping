/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:14:46 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 00:07:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	ft_fill_hdr_icmp(t_icmphdr_echo *packet)
{
	t_conf	*conf;

	conf = get_conf();
	packet->type = ICMP_ECHO;
	packet->code = 0;
	packet->checksum = 0;
	packet->identifier = ft_htons(conf->id_icmp);
	packet->sequence = ft_htons(0);
	packet->checksum = ft_packet_checksum((void *)packet, get_icmp_size());
	ft_pdeb("icmphdr_echo: checksum %#06x\n", packet->checksum);
	if (DEBUG)
		dprintf(DEBUG_FD, "icmphdr_echo: packet len %ld\n", sizeof(*packet));
}

void	ft_hdr_icmp_seq_inc(void)
{
	t_conf			*conf;
	t_icmphdr_echo	*pkt;

	conf = get_conf();
	pkt = ft_packet_get_icmp_echo(&conf->packet);
	conf->sequence++;
	pkt->sequence = ft_htons(conf->sequence);
	pkt->checksum = 0;
	pkt->checksum = ft_packet_checksum((void *)pkt, get_icmp_size());
}

void	ft_hdr_icmp_echo_fill(void *packet)
{
	t_conf	*conf;

	if (gettimeofday(packet + PACK_LEN_ICMP_ECHO, NULL) == -1 && DEBUG)
		ft_dprintf(2, "Failed to get time of day\n");
	conf = get_conf();
	ft_memcpy(packet + PACK_LEN_ICMP_ECHO + PADDING, \
												conf->data_icmp, conf->size);
	ft_fill_hdr_icmp(packet);
}
