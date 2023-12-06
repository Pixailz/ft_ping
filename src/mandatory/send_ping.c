/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:34:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/06 12:21:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bool	send_ping(const struct sockaddr *dst)
{
	t_conf	*conf;
	long	ret;

	conf = get_conf();
	ret = sendto(conf->socket, conf->packet, PACKET_SIZE, 0, dst, sizeof(*dst));
	if (ret == -1)
		ft_perr("sendto");
	conf->stats.send_ts = ft_getnow_ms();
	conf->stats.nb_trans++;
	ft_pdeb("Sended packet\n");
	packet_print(conf->packet);
	if (ft_getnow_ms() - conf->begin >= conf->timeout * A_SEC)
		return (TRUE);
	alarm(conf->linger);
	return (FALSE);
}
