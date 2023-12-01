/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 12:09:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

t_bool	post_parse_incompatible_opt(void)
{
	if (ft_optget("flood")->is_present && ft_optget("interval")->is_present)
	{
		dprintf(2, "./rsc/ping: -f and -i incompatible options");
		return (TRUE);
	}
	return (FALSE);
}

t_bin	post_parse_base(void)
{
	t_opts		*opts;
	t_bin		retv;

	retv = 0;
	opts = ft_get_opts(0);
	if (opts->err & ERR_UNK_OPT)
	{
		unknown_arg();
		retv = BIT_01;
	}
	if (!opts->value)
	{
		dprintf(2, PROG_NAME ": missing host operand\n");
		try_help_usage();
		retv = BIT_07;
	}
	return (retv);
}

t_bin	post_parse(void)
{
	t_conf	*conf;
	t_bin	retv;

	retv = post_parse_base();
	if (retv)
		return (retv);
	if (post_parse_cmd_opt())
		return (BIT_02);
	if (post_parse_incompatible_opt())
		return (BIT_03);
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
