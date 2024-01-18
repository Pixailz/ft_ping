/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:21:19 by brda-sil          #+#    #+#             */
/*   Updated: 2024/01/18 15:47:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bin	init_config(void)
{
	t_conf	*conf;

	conf = get_conf();
	if (!conf)
	{
		dprintf("malloc" SEP "failed to malloc t_conf\n");
		return (BIT_01);
	}
	return (BIT_00);
}

/*
	1. get raw socket for ICMP
	2. set timeout on recv
	3. packet include iphdr
 */
int	ft_create_sock_echo(void)
{
	int				sock;
	struct timeval	tv;
	t_opt			*opt;

	if (getuid())
		return (-1);
	sock = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sock == -1)
		return (-2);
	opt = ft_optget("linger");
	tv.tv_usec = 0;
	if (opt->is_present)
		tv.tv_sec = ft_atoll(opt->value->value);
	else
		tv.tv_sec = FT_PING_LINGER;
	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1)
		return (-3);
	if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (int [1]){1}, \
															sizeof(int)) == -1)
		return (-4);
	return (sock);
}

t_bin	init_socket(void)
{
	t_conf	*conf;
	int		socket;

	conf = get_conf();
	socket = ft_create_sock_echo();
	if (socket < 0)
	{
		if (socket == -1)
			ft_dprintf(2, "ft_ping: Lacking privilege for icmp packet\n");
		if (socket == -2)
			ft_dprintf(2, "get_sock_echo: failed to get raw socket\n");
		if (socket == -3)
			ft_dprintf(2, "get_sock_echo: failed to set timeout on recv\n");
		if (socket == -4)
			ft_dprintf(2, "get_sock_echo: failed to set IP_HDRINCL\n");
		return (BIT_01);
	}
	conf->socket = socket;
	return (BIT_00);
}

t_bin	init_packet(void)
{
	t_conf	*conf;

	conf = get_conf();
	ft_memset(conf->packet, 0, PACKET_SIZE);
	ft_hdr_ip_fill((void *)conf->packet);
	ft_hdr_icmp_echo_fill((void *)conf->packet + LEN_HDR_IP);
	return (BIT_00);
}

t_bin	init_signal(void)
{
	if (signal(SIGALRM, SIG_IGN) == SIG_ERR)
	{
		ft_dprintf(2, "signal: failed to ingore SIGALRM\n");
		return (BIT_01);
	}
	if (signal(SIGINT, &ft_ping_interrupt) == SIG_ERR)
	{
		ft_dprintf(2, "signal: failed to set SIGTINT\n");
		return (BIT_02);
	}
	return (BIT_00);
}
