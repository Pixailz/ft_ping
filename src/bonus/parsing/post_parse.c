/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 16:17:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

t_bool	post_parse_incompatible_opt(void)
{
	if (ft_optget("flood")->is_present && ft_optget("interval")->is_present)
	{
		dprintf(2, "%s: -f and -i incompatible options", \
													ft_get_opts(0)->prog_name);
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

	conf = get_conf();
	if (post_parse_cmd_opt())
		return (BIT_02);
	if (post_parse_pattern(conf))
		return (BIT_01);
	if (post_parse_incompatible_opt())
		return (BIT_01);
	retv = post_parse_base();
	if (retv)
		return (retv);
	post_parse_count(conf);
	post_parse_timeout(conf);
	post_parse_linger(conf);
	post_parse_interval(conf);
	post_parse_ttl(conf);
	post_parse_preload(conf);
	return (BIT_00);
}
