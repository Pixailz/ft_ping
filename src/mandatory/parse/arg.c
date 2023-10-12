/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:33:02 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/12 21:24:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	get_arg_type(char *arg)
{
	t_bool	type = 0;

	if (arg[0] != '-')
		return (type);
	if (arg[1] == '-')
		type = 2;
	else
		type = 1;
	ft_dprintf(DEBUG_FD, "arg [%s] is of type: %d\n", arg, type);
	return (type);
}

void	parse_arg(int ac, char **av)
{
	int	counter;
	int	arg_type;

	counter = 1;
	(void)ac;
	while (av[counter])
	{
		arg_type = get_arg_type(av[counter]);
		if (!arg_type)
			parse_argument(av[counter]);
		else if (arg_type == 1)
			parse_short(av[counter]);
		else if (arg_type == 2)
			parse_long(av[counter]);
		counter++;
	}
}

void	parse_argument(char *arg)
{
	(void)arg;
}
