/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_pong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:53:19 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/05 23:52:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static t_bool	recv_echo_reply(t_packet *pong_pkt)
{
	t_conf			*conf;
	struct iovec	io;
	struct msghdr	msg;
	long			ret;

	conf = get_conf();
	ft_memset(&io, 0, sizeof(io));
	ft_memset(&msg, 0, sizeof(msg));
	io.iov_base = pong_pkt->data;
	io.iov_len = get_packet_size();
	msg.msg_iov = &io;
	msg.msg_iovlen = 1;
	ret = recvmsg(conf->socket, &msg, 0);
	return (ret == -1);
}

static t_bool	check_echo_reply(t_packet *pkt)
{
	t_icmphdr_echo	*icmphdr_echo;
	t_conf			*conf;

	conf = get_conf();
	icmphdr_echo = ft_packet_get_icmp_echo(pkt);
	if (icmphdr_echo->type != ICMP_ECHOREPLY)
	{
		if ((int)icmphdr_echo->type == ICMP_ECHO)
			return (FALSE);
		print_icmp_error(pkt->data);
		conf->stats.nb_err++;
	}
	else
	{
		conf->stats.nb_recv++;
		print_pong_stats(pkt->data, icmphdr_echo);
	}
	return (TRUE);
}

void	recv_pong(void)
{
	t_packet		pong_pkt;
	t_conf			*conf;

	pong_pkt = ft_packet_get();
	conf = get_conf();
	while (TRUE)
	{
		ft_bzero(pong_pkt.data, sizeof(pong_pkt.data));
		if (recv_echo_reply(&pong_pkt))
		{
			print_icmp_timeout();
			conf->stats.nb_err++;
			break ;
		}
		if (check_echo_reply(&pong_pkt))
			break ;
	}
}
