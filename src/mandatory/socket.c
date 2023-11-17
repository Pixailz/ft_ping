/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:28:47 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 11:42:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

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

	sock = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sock == -1)
		return (-1);
	opt = ft_optget("linger");
	tv.tv_usec = 0;
	if (opt->is_present)
		tv.tv_sec = ft_atoll(opt->value->value);
	else
		tv.tv_sec = FT_PING_LINGER;
	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1)
		return (-2);
	if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (int[1]){1}, sizeof(int)) == -1)
		return (-3);
	return (sock);
}
