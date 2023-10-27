/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:38:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/27 03:57:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	unknown_arg(char *prog_path)
{
	t_opts		*opts;

	opts = ft_sin_opts(0);
	if (opts->err_param_name)
		ft_dprintf(2, "%s: invalid option -- '%s'\n", \
											prog_path, opts->err_param_name);
	else if (opts->err_param_short)
		ft_dprintf(2, "%s: invalid option -- '%c'\n", \
											prog_path, opts->err_param_short);
	ft_putstr_fd("Try 'ft_ping --help' or 'ft_ping --usage'", 2);
	ft_putendl_fd(" for more information.", 2);
}

t_bool	version(void)
{
	ft_printf("ft_ping (ft_libft) %s\n\n", VERSION);
	ft_putendl_fd("Written by Pixailz", 1);
	return (TRUE);
}

t_bool	usage(void)
{
	ft_putstr_fd("Usage: ping [-v?V] [--help] [--usage] [--verbose]", 1);
	ft_putendl_fd(" [--version]", 1);
	ft_putendl_fd("            HOST ...", 1);
	return (TRUE);
}

t_bool	help(void)
{
	ft_putendl_fd("Usage: ping [OPTION...] HOST ...", 1);
	ft_putendl_fd("Send ICMP ECHO_REQUEST packets to network hosts.\n", 1);
	ft_putendl_fd(" Options valid for all request types:\n", 1);
	ft_putendl_fd("  -v, --verbose              verbose output", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd(" Options valid for --echo requests:\n", 1);
	ft_putendl_fd("  -?, --help                 give this help list", 1);
	ft_putendl_fd("      --usage                give a short usage message", 1);
	ft_putendl_fd("  -V, --version              print program version", 1);
	ft_putendl_fd("", 1);
	ft_putstr_fd("Mandatory or optional arguments to long options are also", 1);
	ft_putendl_fd(" mandatory or optional", 1);
	ft_putendl_fd("for any corresponding short options.\n", 1);
	ft_putstr_fd("Options marked with (root only) are available", 1);
	ft_putendl_fd(" only to superuser.\n", 1);
	ft_putendl_fd("Report bugs to <pixailz1@gmail.com>.", 1);
	return (TRUE);
}
