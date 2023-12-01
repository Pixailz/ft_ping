/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse_conf_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:44:42 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 12:20:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

void	post_parse_count(t_conf *conf)
{
	t_opt	*opt;

	opt = ft_optget("count");
	if (opt->is_present)
		conf->nb_packet = ft_atoll(opt->value->value);
	else
		conf->nb_packet = FT_PING_NB_PKT;
	if (conf->nb_packet == 0)
		conf->nb_packet = -1;
}

void	post_parse_timeout(t_conf *conf)
{
	t_opt	*opt;

	opt = ft_optget("timeout");
	if (opt->is_present)
		conf->timeout = ft_atoll(opt->value->value);
	else
		conf->timeout = FT_PING_TIMEOUT;
}

void	post_parse_linger(t_conf *conf)
{
	t_opt	*opt;

	opt = ft_optget("linger");
	if (opt->is_present)
		conf->linger = ft_atoll(opt->value->value);
	else
		conf->linger = FT_PING_LINGER;
}

void	post_parse_interval(t_conf *conf)
{
	t_opt	*interval;
	t_opt	*flood;

	flood = ft_optget("flood");
	if (flood->is_present)
	{
		conf->interval = 0;
		conf->flood = TRUE;
	}
	else
	{
		interval = ft_optget("interval");
		if (interval->is_present)
			conf->interval = ft_atoll(interval->value->value);
		else
			conf->interval = FT_PING_INTERVAL;
		if (conf->interval < 0)
			conf->interval = 0;
	}
}

void	post_parse_ttl(t_conf *conf)
{
	t_opt	*opt;

	opt = ft_optget("ttl");
	if (opt->is_present)
		conf->ttl = ft_atoll(opt->value->value);
	else
		conf->ttl = FT_PING_TTL;
	if (conf->ttl < 0)
		conf->ttl = 0;
}
