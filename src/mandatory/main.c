/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:17:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/06 12:33:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bin	ft_ping(int ac, char **av)
{
	int	ret;

	if (init_config())
		return (BIT_01);
	if (init_signal())
		return (BIT_01);
	ret = parse_opts(ac, av);
	if (ret == BIT_02)
		return (0);
	else if (ret != 0)
		return (ret);
	if (init_socket())
		return (BIT_01);
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
