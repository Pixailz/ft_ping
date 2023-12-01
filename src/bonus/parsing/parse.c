/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 17:49:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

t_bin	parse_opts(int ac, char **av)
{
	ft_optadd("help", '?', OPT_FLAG);
	ft_optadd("usage", 0, OPT_FLAG);
	ft_optadd("verbose", 'v', OPT_FLAG);
	ft_optadd("version", 'V', OPT_FLAG);
	ft_optadd("count", 'c', OPT_SINGLE);
	ft_optadd("interval", 'i', OPT_SINGLE);
	ft_optadd("ttl", 0, OPT_SINGLE);
	ft_optadd("flood", 'f', OPT_FLAG);
	ft_optadd("preload", 'l', OPT_SINGLE);
	ft_optadd("numeric", 'n', OPT_FLAG);
	ft_optadd("pattern", 'p', OPT_SINGLE);
	ft_optadd("size", 's', OPT_SINGLE);
	ft_optadd("tos", 'T', OPT_SINGLE);
	ft_optadd("ttl", 0, OPT_SINGLE);
	ft_optadd("timeout", 'w', OPT_SINGLE);
	ft_optadd("linger", 'W', OPT_SINGLE);
	ft_optadd("quiet", 'q', OPT_FLAG);
	ft_optparse(ac, av);
	return (post_parse());
}
