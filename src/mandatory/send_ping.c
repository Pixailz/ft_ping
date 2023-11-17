/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:34:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 09:06:45 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	send_ping(const struct sockaddr *dst)
{
	t_conf	*conf;
	long	ret;

	conf = get_conf();
	ret = sendto(conf->socket, conf->packet, PACKET_SIZE, 0, dst, sizeof(*dst));
	if (ret == -1)
		perror("sendto");
	conf->stats.send_ts = ft_getnow_ms();
	conf->stats.nb_trans++;
	dprintf(DEBUG_FD, "Sended packet\n");
	packet_print(conf->packet);
	alarm(FT_PING_PKT_INTERVAL);
}
