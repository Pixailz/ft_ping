/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 05:58:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bool	post_parse_incompatible_opt(void)
{
	if (ft_optget("flood")->is_present && ft_optget("interval")->is_present)
	{
		ft_pdeb("%s: -f and -i incompatible options\n", PROG_NAME);
		return (TRUE);
	}
	return (FALSE);
}

t_bin	post_parse(void)
{
	t_conf	*conf;

	if (!ft_get_opts(0)->value)
	{
		ft_perr("%s", PROG_NAME ": missing host operand\n");
		ft_try_help_usage();
		return (BIT_03);
	}
	conf = get_conf();
	if (post_parse_pattern(conf))
		return (BIT_02);
	if (post_parse_incompatible_opt())
		return (BIT_02);
	post_parse_count(conf);
	post_parse_timeout(conf);
	post_parse_linger(conf);
	post_parse_interval(conf);
	post_parse_ttl(conf);
	post_parse_preload(conf);
	post_parse_tos(conf);
	return (BIT_00);
}
