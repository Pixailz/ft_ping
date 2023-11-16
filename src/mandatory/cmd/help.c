/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:38:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 06:59:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	help_header(void)
{
	ft_putendl_fd("\
Usage: " PROG_NAME " [OPTION...] HOST ...\n\
Send ICMP ECHO_REQUEST packets to network hosts.\n", 1);
}

void	help_part_1(void)
{
	ft_putendl_fd("\
 Options valid for all request types:\n\n\
  -c, --count=NUMBER         stop after sending NUMBER packets\n\
  -v, --verbose              verbose output\n\
  -w, --timeout=N            stop after N seconds\n\
  -W, --linger=N             number of seconds to wait for response\n\
", 1);
}

void	help_part_2(void)
{
	ft_putendl_fd("\
 Options valid for --echo requests:\n\n\
  -?, --help                 give this help list\n\
      --usage                give a short usage message\n\
  -V, --version              print program version\n\
", 1);
}

void	help_footer(void)
{
	ft_putendl_fd("\
Mandatory or optional arguments to long options are also mandatory or optional\n\
for any corresponding short options.\n\n\
Options marked with (root only) are available only to superuser.\n\n\
Report bugs to <pixailz1@gmail.com>.", 1);
}

t_bool	help(void)
{
	help_header();
	help_part_1();
	help_part_2();
	help_footer();
	return (TRUE);
}
