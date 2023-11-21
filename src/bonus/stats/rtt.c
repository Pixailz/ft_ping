/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:58:51 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/21 04:33:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

t_ts	ft_getnow_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	return (tv.tv_sec * A_SEC + tv.tv_usec);
}

void	update_stats_rtt(t_ts rtt, t_uint16 sequence)
{
	t_conf	*conf;

	conf = get_conf();
	if (!sequence)
	{
		conf->stats.rtt_min = rtt;
		conf->stats.rtt_avg = rtt;
		conf->stats.rtt_max = rtt;
	}
	else
	{
		if (rtt < conf->stats.rtt_min)
			conf->stats.rtt_min = rtt;
		if (rtt > conf->stats.rtt_max)
			conf->stats.rtt_max = rtt;
		conf->stats.rtt_avg += rtt;
	}
}
