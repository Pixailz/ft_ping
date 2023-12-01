/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse_conf_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:44:42 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 12:41:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

void	post_parse_preload(t_conf *conf)
{
	t_opt	*opt;

	opt = ft_optget("preload");
	if (opt->is_present)
		conf->preload = ft_atoll(opt->value->value);
	else
		conf->preload = 0;
}
