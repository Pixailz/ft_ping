/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:17:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 05:14:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	ft_ping(int ac, char **av)
{
	if (init_config())
		return ;
	if (init_signal())
		return ;
	if (parse_opts(ac, av))
		return ;
	if (init_socket())
		return ;
	init_packet();
	process_args();
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_ping(ac, av);
		free_data();
	}
	else
	{
		dprintf(2, PROG_NAME ": missing host operand\n");
		try_help_usage();
	}
	return (0);
}
