/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_pong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:53:19 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 15:46:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

static t_bool	recv_echo_reply(char *pong_pkt)
{
	t_conf			*conf;
	struct iovec	io;
	struct msghdr	msg;
	long			ret;

	conf = get_conf();
	ft_memset(&io, 0, sizeof(io));
	ft_memset(&msg, 0, sizeof(msg));
	io.iov_base = pong_pkt;
	io.iov_len = get_packet_size();
	msg.msg_iov = &io;
	msg.msg_iovlen = 1;
	ret = recvmsg(conf->socket, &msg, 0);
	return (ret == -1);
}

static t_bool	check_echo_reply(char *pkt)
{
	t_icmphdr_echo	*icmphdr_echo;
	t_conf			*conf;

	conf = get_conf();
	icmphdr_echo = (t_icmphdr_echo *)(pkt + LEN_HDR_IP);
	if (icmphdr_echo->type != ICMP_ECHOREPLY)
	{
		if (icmphdr_echo->type == ICMP_ECHO)
			return (FALSE);
		print_icmp_error(pkt);
		conf->stats.nb_err++;
	}
	else
	{
		conf->stats.nb_recv++;
		print_pong_stats(pkt, icmphdr_echo);
	}
	return (TRUE);
}

void	recv_pong(void)
{
	char			pong_pkt[MAX_PACKET_SIZE];
	t_conf			*conf;

	conf = get_conf();
	while (TRUE)
	{
		ft_memset(pong_pkt, 0, sizeof(pong_pkt));
		if (recv_echo_reply(pong_pkt))
		{
			print_icmp_timeout();
			conf->stats.nb_err++;
			break ;
		}
		if (check_echo_reply(pong_pkt))
			break ;
	}
}
