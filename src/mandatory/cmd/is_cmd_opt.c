/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 12:58:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bool	is_cmd_opt(t_opt opt)
{
	if (!ft_strcmp(opt.name, "help"))
		return (help());
	if (!ft_strcmp(opt.name, "usage"))
		return (usage());
	if (!ft_strcmp(opt.name, "version"))
		return (version());
	return (FALSE);
}
