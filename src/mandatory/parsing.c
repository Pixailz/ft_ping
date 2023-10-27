/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/27 03:55:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bool	post_parse_opt(t_opt opt)
{
	if (!ft_strcmp(opt.name, "help"))
		return (help());
	if (!ft_strcmp(opt.name, "usage"))
		return (usage());
	if (!ft_strcmp(opt.name, "version"))
		return (version());
	return (FALSE);
}

void	post_parse(char *prog_path)
{
	t_opts		*opts;
	t_opt_order	*ptr;

	opts = ft_sin_opts(0);
	if (opts->err & ERR_UNK_OPT)
		unknown_arg(prog_path);
	ptr = opts->opt_order;
	while (ptr)
	{
		if (post_parse_opt(*ptr->opt))
			break ;
		ptr = ptr->next;
	}
}

void	parse_arg(int ac, char **av)
{
	ft_optadd("help", '?', OPT_FLAG);
	ft_optadd("usage", 0, OPT_FLAG);
	ft_optadd("verbose", 'v', OPT_FLAG);
	ft_optadd("version", 'V', OPT_FLAG);
	ft_optparse(ac, av);
	post_parse(av[0]);
}
