/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 15:15:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static void	post_parse_count(t_conf *conf)
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

static void	post_parse_timeout(t_conf *conf)
{
	t_opt	*opt;

	opt = ft_optget("timeout");
	if (opt->is_present)
		conf->timeout = ft_atoll(opt->value->value);
	else
		conf->timeout = FT_PING_TIMEOUT;
}

static void	post_parse_linger(t_conf *conf)
{
	t_opt	*opt;

	opt = ft_optget("linger");
	if (opt->is_present)
		conf->linger = ft_atoll(opt->value->value);
	else
		conf->linger = FT_PING_LINGER;
}

static void	post_parse_interval(t_conf *conf)
{
	t_opt	*opt;

	opt = ft_optget("interval");
	if (opt->is_present)
		conf->interval = ft_atoll(opt->value->value);
	else
		conf->interval = FT_PING_INTERVAL;
	if (conf->interval < 0)
		conf->interval = 0;
}

static void	post_parse_ttl(t_conf *conf)
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
