/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:17:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/21 03:17:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bin	ft_ping(int ac, char **av)
{
	if (init_config())
		return 2;
	if (init_signal())
		return 3;
	if (parse_opts(ac, av))
		return 4;
	if (init_socket())
		return (5);
	init_packet();
	process_args();
	return (get_conf()->stats.nb_err != 0);
}

int	main(int ac, char **av)
{
	int	ret;

	if (ac > 1)
	{
		ret = ft_ping(ac, av);
		free_data();
	}
	else
	{
		dprintf(2, PROG_NAME ": missing host operand\n");
		try_help_usage();
		ret = 64;
	}
	return (ret);
}
