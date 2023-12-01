/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:17:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 12:07:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

t_bin	ft_ping(int ac, char **av)
{
	int	ret;

	if (init_config())
		return (2);
	if (init_signal())
		return (3);
	ret = parse_opts(ac, av);
	if (ret == 2)
		return (4);
	else if (ret == 1)
		return (0); // cmd flags
	else if (ret != 0)
		return (ret);
	if (init_socket())
		return (5);
	init_packet();
	process_args();
	ret = get_conf()->stats.nb_err != 0;
	return (ret);
}

int	main(int ac, char **av)
{
	char	ret;

	ret = ft_ping(ac, av);
	free_data();
	return (ret);
}
