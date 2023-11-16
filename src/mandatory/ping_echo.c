/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:34:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 00:43:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static void	send_echo(const struct sockaddr *dst)
{
	long	ret;
	t_conf	*conf;

	conf = get_conf();
	ret = sendto(conf->socket, conf->packet, PACKET_SIZE, 0, dst, sizeof(*dst));
	if (ret == -1)
		perror("sendto");
	ft_hdr_icmp_seq_inc();
	packet_print_raw(conf->packet);
}
	// packet_print(conf->packet);

void	ft_send_echo(void)
{
	t_conf	*conf;
	int		counter;

	conf = get_conf();
	counter = 2;
	while (counter)
	{
		send_echo(&conf->cur_target.addr);
		recv_echo_reply();
		counter--;
	}
}
