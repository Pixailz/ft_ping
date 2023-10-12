/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:33:02 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/12 20:24:17 by brda-sil         ###   ########.fr       */
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
	ft_dprintf(DEBUG_FD, "[parse] [%s] is short", arg);
	return (TRUE);
}

void	parse_arg(int ac, char **av)
{
	int	counter;

	counter = 1;
	(void)ac;
	while (av[counter])
	{
		if (is_arg_short(av[counter]))
			parse_short(av[counter] + 1);
		else
			parse_long(av[counter]);
		counter++;
	}
}

void	parse_long(char *arg)
{
	(void)arg;
}


void	parse_short(char *arg)
{
	(void)arg;
}
