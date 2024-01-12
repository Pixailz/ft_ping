/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:34:50 by brda-sil          #+#    #+#             */
/*   Updated: 2024/01/12 13:26:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

void	ft_ping_run(void)
{
	t_conf			*conf;
	t_icmphdr_echo	*pkt;

	conf = get_conf();
	if (send_ping(&conf->cur_target.addr))
		return ;
	recv_pong();
	ft_hdr_icmp_seq_inc();
	pkt = (t_icmphdr_echo *)(conf->packet + LEN_HDR_IP);
	if (DEBUG)
		dprintf(DEBUG_FD, "icmphdr_echo (inc): checksum %#06x\n", pkt->checksum);
}
