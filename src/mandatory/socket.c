/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:28:47 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/16 19:53:43 by brda-sil         ###   ########.fr       */
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
	int				param[1];
	struct timeval	tv;

	sock = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sock == -1)
		return (-1);
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1)
		return (-2);
	param[0] = 1;
	if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &param, sizeof(int)) \
																		== -1)
		return (-3);
	return (sock);
}
