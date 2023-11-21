/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:38:09 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/21 03:57:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bool	exec_cmd_opt(t_opt opt)
{
	t_bool	ret;

	ret = TRUE;
	if (!ft_strcmp(opt.name, "help"))
		help();
	else if (!ft_strcmp(opt.name, "usage"))
		usage();
	else if (!ft_strcmp(opt.name, "version"))
		version();
	else
		ret = FALSE;
	return (ret);
}

t_bool	post_parse_cmd_opt(void)
{
	t_opts		*opts;
	t_opt_order	*ptr;

	opts = ft_get_opts(0);
	ptr = opts->opt_order;
	while (ptr)
	{
		if (ptr->opt)
			if (exec_cmd_opt(*ptr->opt))
				return TRUE;
		ptr = ptr->next;
	}
	return (FALSE);
}
