/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse_conf_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:44:42 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 04:53:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	post_parse_preload(t_conf *conf)
{
	t_opt	*opt;

	opt = ft_optget("preload");
	if (opt->is_present)
		conf->preload = ft_atoll(opt->value->value);
	else
		conf->preload = 0;
}

void	post_parse_tos(t_conf *conf)
{
	t_opt	*opt;

	opt = ft_optget("tos");
	if (opt->is_present)
		conf->tos = ft_atou(opt->value->value);
	else
		conf->tos = 0;
}
