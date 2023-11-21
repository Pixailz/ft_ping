/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/21 04:33:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

t_bin	post_parse(void)
{
	t_conf	*conf;

	if (post_parse_cmd_opt())
		return (BIT_02);
	conf = get_conf();

	post_parse_count(conf);
	post_parse_timeout(conf);
	post_parse_linger(conf);
	post_parse_interval(conf);
	post_parse_ttl(conf);
	dprintf(DEBUG_FD, "conf->nb_packet %d\n", conf->nb_packet);
	dprintf(DEBUG_FD, "conf->timeout   %d\n", conf->timeout);
	dprintf(DEBUG_FD, "conf->linger    %d\n", conf->linger);
	dprintf(DEBUG_FD, "conf->interval  %d\n", conf->interval);
	dprintf(DEBUG_FD, "conf->ttl       %d\n", conf->ttl);
	return (BIT_00);
}
