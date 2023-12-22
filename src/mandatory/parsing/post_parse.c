/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/22 01:02:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bin	post_parse_base(void)
{
	t_opts		*opts;

	opts = ft_get_opts(0);
	if (opts->err & ERR_UNK_OPT)
	{
		unknown_arg();
		return (BIT_01);
	}
	if (!opts->value)
	{
		ft_dprintf(2, PROG_NAME ": missing host operand\n");
		try_help_usage();
		return (BIT_07);
	}
	return (0);
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
	retv = post_parse_base();
	if (retv)
		return (retv);
	post_parse_count(conf);
	post_parse_timeout(conf);
	post_parse_linger(conf);
	post_parse_interval(conf);
	return (BIT_00);
}
