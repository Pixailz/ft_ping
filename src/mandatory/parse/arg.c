/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:33:02 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/30 05:51:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	parse_arg(int ac, char **av)
{
	int	counter;

	counter = 1;
	while (av[counter])
	{
		if (is_arg_short(av[counter]))
			parse_arg_short(av[counter] + 1);
		else
			parse_param(av[counter]);
		counter++;
	}
}