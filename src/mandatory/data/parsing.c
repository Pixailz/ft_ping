/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/16 19:54:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bool	is_cmd_opt(t_opt opt)
{
	if (!ft_strcmp(opt.name, "help"))
		return (help());
	if (!ft_strcmp(opt.name, "usage"))
		return (usage());
	if (!ft_strcmp(opt.name, "version"))
		return (version());
	return (FALSE);
}

void	post_parse_cmd_opt(void)
{
	t_opts		*opts;
	t_opt_order	*ptr;

	opts = ft_get_opts(0);
	ptr = opts->opt_order;
	while (ptr)
	{
		if (ptr->opt)
		{
			ft_pdeb("cmd opt {%s} at %d\n", \
									ptr->value, (ptr - opts->opt_order) + 1);
			if (is_cmd_opt(*ptr->opt))
				break ;
		}
		ptr = ptr->next;
	}
}

t_bin	parse_opts(int ac, char **av)
{
	t_opts		*opts;

	ft_optadd("help", '?', OPT_FLAG);
	ft_optadd("usage", 0, OPT_FLAG);
	ft_optadd("verbose", 'v', OPT_FLAG);
	ft_optadd("version", 'V', OPT_FLAG);
	ft_optadd("count", 'c', OPT_SINGLE);
	ft_optadd("timeout", 'w', OPT_SINGLE);
	ft_optadd("linger", 'W', OPT_SINGLE);
	ft_optparse(ac, av);
	opts = ft_get_opts(0);
	if (opts->err & ERR_UNK_OPT)
	{
		unknown_arg();
		return (BIT_01);
	}
	post_parse_cmd_opt();
	return (BIT_00);
}
