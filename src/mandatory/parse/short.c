/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:31:44 by brda-sil          #+#    #+#             */
/*   Updated: 2023/08/01 03:11:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bool	is_arg_short(char *arg)
{
	if (arg[0] != '-' || ft_strlen(arg) != 2)
		return (FALSE);
	arg++;
	if (!ft_is_str(arg, ft_isalnum))
		return (FALSE);
	ft_dprintf(DEBUG_FD, "[parse] [%s] is short");
	return (TRUE);
}

void	parse_arg_short(char *arg)
{
	(void)arg;
}
