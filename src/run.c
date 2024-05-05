/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:34:50 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/05 23:22:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	ft_ping_run(void)
{
	t_conf			*conf;
	t_icmphdr_echo	*pkt;

	conf = get_conf();
	if (send_ping(&conf->cur_target.addr))
		return ;
	recv_pong();
	ft_hdr_icmp_seq_inc();
	pkt = ft_packet_get_icmp_echo(&conf->packet);
	if (DEBUG)
		dprintf(DEBUG_FD, "icmphdr_echo (inc): checksum %#06x\n", pkt->checksum);
}
