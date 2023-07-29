/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:32:18 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/29 21:32:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ping.h>

t_bool	is_arg_long(char *arg)
{
	if (arg[0] != '-' && arg[1] != '-')
		return (FALSE);
	arg += 2;
	if (!ft_is_str(arg, ft_isalnum))
		return (FALSE);
	return (TRUE);
}

void	parse_arg_long(char *arg)
{
	printf("[%s] is long\n", arg);
}
