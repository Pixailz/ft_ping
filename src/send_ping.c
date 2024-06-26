/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:34:50 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/05 23:23:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bool	send_ping(const struct sockaddr *dst)
{
	t_conf	*conf;
	long	ret;

	conf = get_conf();
	ret = sendto(conf->socket, conf->packet.data, get_packet_size(), 0, dst, \
																sizeof(*dst));
	if (ret == -1)
		dprintf(2, "sendto");
	conf->stats.send_ts = ft_getnow_ms();
	conf->stats.nb_trans++;
	ft_pdeb("Sended packet\n");
	packet_print(conf->packet.data);
	if (ft_getnow_ms() - conf->begin >= conf->timeout * A_SEC)
		return (TRUE);
	alarm(conf->linger);
	return (FALSE);
}
