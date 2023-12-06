/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/06 12:27:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/* Those are the mandatory for me, at least for debuging the process
 -W and -w respectivly linger and timeout
 -i interval between ping
 -c number of ping, usefull for valgrind before implementing signals
 */
t_bin	parse_opts(int ac, char **av)
{
	ft_optadd("help", '?', OPT_FLAG);
	ft_optadd("usage", 0, OPT_FLAG);
	ft_optadd("verbose", 'v', OPT_FLAG);
	ft_optadd("version", 'V', OPT_FLAG);
	ft_optadd("count", 'c', OPT_SINGLE);
	ft_optadd("interval", 'i', OPT_SINGLE);
	ft_optadd("timeout", 'w', OPT_SINGLE);
	ft_optadd("linger", 'W', OPT_SINGLE);
	ft_optparse(ac, av);
	ft_optparse(ac, av);
	return (post_parse());
}
