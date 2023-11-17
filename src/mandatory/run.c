/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:34:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 09:45:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	ft_ping_run(__attribute__((unused)) int sig)
{
	t_conf			*conf;
	t_icmphdr_echo	*pkt;

	conf = get_conf();
	send_ping(&conf->cur_target.addr);
	recv_pong();
	ft_hdr_icmp_seq_inc();
	pkt = (t_icmphdr_echo *)(conf->packet + LEN_HDR_IP);
	dprintf(DEBUG_FD, "icmphdr_echo (inc): checksum 0x%04x\n", pkt->checksum);
}
