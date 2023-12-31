/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 06:02:30 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/03 16:26:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

void	usage(void)
{
	ft_printf("\
Usage: %s [-v?V] [-c NUMBER] [-w N] [-W N] [--count=NUMBER] [--verbose]\n\
            [--timeout=N] [--linger=N] [--help] [--usage] [--version]\n\
            HOST ...\n", PROG_NAME);
}

void	try_help_usage(void)
{
	ft_dprintf(2, "Try '" PROG_NAME " --help' or '" PROG_NAME " --usage' " \
													"for more informations.\n");
}

void	unknown_arg(void)
{
	t_opts		*opts;

	opts = ft_get_opts(0);
	if (opts->err_param_name)
		ft_dprintf(2, "%s: unrecognized option '%s'\n", \
										opts->av[0], opts->err_param_name);
	else if (opts->err_param_short)
		ft_dprintf(2, "%s: invalid option -- '%c'\n", \
										opts->av[0], opts->err_param_short);
	try_help_usage();
}
