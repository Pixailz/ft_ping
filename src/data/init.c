/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:21:19 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 22:06:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bin	init_config(void)
{
	t_conf	*conf;

	conf = get_conf();
	if (!conf)
	{
		ft_perr(PROG_NAME": malloc: failed to malloc t_conf\n");
		return (BIT_01);
	}
	return (BIT_00);
}

/*
	1. get raw socket for ICMP
	2. set timeout on recv
	3. packet include iphdr
 */
int	ft_create_sock_echo(int *sock)
{
	t_opt	*opt;
	int		tv;

	if (getuid())
		return (1);
	*sock = ft_socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (*sock == -1)
		return (2);
	opt = ft_optget("linger");
	if (opt->is_present)
		tv = ft_atoll(opt->value->value);
	else
		tv = FT_PING_LINGER;
	tv *= A_SEC;
	if (ft_setsockopt_timeout(*sock, tv))
		return (3);
	if (ft_setsockopt_ipheader(*sock))
		return (4);
	return (0);
}

t_bin	init_socket(void)
{
	t_conf	*conf;
	int		sock;
	int		retv;

	conf = get_conf();
	retv = ft_create_sock_echo(&sock);
	if (retv)
	{
		if (retv == 1)
			ft_perr("ft_ping: Lacking privilege for icmp packet\n");
		if (retv == 2)
			ft_perr("get_sock_echo: failed to get raw socket\n");
		if (retv == 3)
			ft_perr("get_sock_echo: failed to set timeout on recv\n");
		if (retv == 4)
			ft_perr("get_sock_echo: failed to set IP_HDRINCL\n");
		return (BIT_01);
	}
	conf->socket = sock;
	return (BIT_00);
}

t_bin	init_packet(void)
{
	t_conf	*conf;

	conf = get_conf();
	ft_hdr_ip_fill(ft_pkt_get_ip(&conf->packet));
	ft_hdr_icmp_echo_fill(ft_pkt_get_icmp_echo(&conf->packet));
	return (BIT_00);
}

t_bin	init_signal(void)
{
	if (signal(SIGALRM, SIG_IGN) == SIG_ERR)
	{
		ft_perr("signal: failed to ingore SIGALRM\n");
		return (BIT_01);
	}
	if (signal(SIGINT, &ft_ping_interrupt) == SIG_ERR)
	{
		ft_perr("signal: failed to set SIGTINT\n");
		return (BIT_02);
	}
	return (BIT_00);
}
