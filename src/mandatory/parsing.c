/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 16:56:23 by brda-sil         ###   ########.fr       */
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

void	post_parse_value(char *value)
{
	t_int4	tmp;

	tmp = ft_ipstr(value);
	if (tmp)
	{
		ft_pdeb("%s is a valid ip\n", value);
	}
	else if (ft_is_goodhost(value))
	{
		ft_pdeb("%s is a valid host\n", value);
	}
	else
	{
		ft_pdeb("%s unknown host\n", value);
	}
}

void	post_parse(char *prog_path)
{
	t_opts		*opts;
	t_opt_order	*ptr;

	opts = ft_sin_opts(0);
	if (opts->err & ERR_UNK_OPT)
		return (unknown_arg(prog_path));
	ptr = opts->opt_order;
	while (ptr)
	{
		ft_pdeb("opt {%s} at %d\n", ptr->value, (ptr - opts->opt_order) + 1);
		if (ptr->opt)
		{
			if (post_parse_opt(*ptr->opt))
				break ;
		}
		else
			post_parse_value(ptr->value);
		ptr = ptr->next;
	}
}

void	parse_arg(int ac, char **av)
{
	ft_optadd("help", '?', OPT_FLAG);
	ft_optadd("usage", 0, OPT_FLAG);
	ft_optadd("verbose", 'v', OPT_FLAG);
	ft_optadd("version", 'V', OPT_FLAG);
	ft_optadd("count", 'c', OPT_SINGLE);
	ft_optadd("timeout", 'w', OPT_SINGLE);
	ft_optadd("linger", 'W', OPT_SINGLE);
	ft_optparse(ac, av);
	post_parse(av[0]);
}
