/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:21:19 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/21 02:59:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bin	init_config(void)
{
	t_conf	*conf;

	conf = get_conf();
	if (!conf)
	{
		ft_perr("malloc" SEP "failed to malloc t_conf\n");
		return (BIT_01);
	}
	return (BIT_00);
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
			dprintf(2, "ft_ping: Lacking privilege for icmp packet\n");
		if (socket == -2)
			dprintf(2, "get_sock_echo: failed to get raw socket\n");
		if (socket == -3)
			dprintf(2, "get_sock_echo: failed to set timeout on recv\n");
		if (socket == -4)
			dprintf(2, "get_sock_echo: failed to set IP_HDRINCL\n");
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

static	void dummy(int sig)
{
	(void)sig;
	dprintf(DEBUG_FD, "SIGALRM received\n");
}

t_bin	init_signal(void)
{
	if (signal(SIGALRM, dummy) == SIG_ERR)
	{
		dprintf(2, "signal: failed to set SIGALRM\n");
		return (BIT_01);
	}
	if (signal(SIGINT, &ft_ping_interrupt) == SIG_ERR)
	{
		dprintf(2, "signal: failed to set SIGTINT\n");
		return (BIT_02);
	}
	return (BIT_00);
}
