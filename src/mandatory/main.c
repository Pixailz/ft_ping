/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:17:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/15 01:50:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

// int	main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		parse_opts(ac, av);
// 		process_args();
// 		ft_free_opts();
// 	}
// 	else
// 	{
// 		ft_dprintf(2, PROG_NAME ": missing host operand\n");
// 		try_help_usage();
// 	}
// 	return (0);
// }

int	get_socket(void)
{
	int				sock;
	struct timeval	tv;

	sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sock == -1)
		return (-1);
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)))
		return (-2);
	return (sock);
}

# include <stdio.h>

void	send_echo(int socket, char *packet, const struct sockaddr *dst)
{
	long	ret;

	ret = sendto(socket, packet, PACKET_SIZE, 0, dst, sizeof(*dst));
	if (ret == -1)
		printf("sendto failed\n");
}

int	main(void)
{
	char				packet[PACKET_SIZE];
	t_int4				dst;
	int					sock;
	struct sockaddr_in	sa;

	inet_pton(AF_INET, "127.0.0.1", &(sa.sin_addr));
	ft_memset(packet, 0, PACKET_SIZE);
	dst = ft_int4_comp(127, 0, 0, 1);
	ft_fill_hdr_ip((void *)packet, dst);
	ft_fill_icmp_echo((void *)packet + LEN_HDR_IP, 0);
	packet_print_raw(packet);
	sock = get_socket();
	send_echo(sock, packet, (const struct sockaddr *)&sa);
	return (0);
}
