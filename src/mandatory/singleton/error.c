/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:04:20 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/30 06:01:09 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_err	*get_error(void)
{
	static t_err	*err = NULL;

	if (err == NULL)
		err = (t_err *)ft_calloc(sizeof(t_err), 1);
	return (err);
}

void	set_error_malloc(t_errno value)
{
	get_error()->malloc &= value;
}

void	set_error(t_emode mode, t_errno value)
{
	if (mode == MALLOC)
		set_error_malloc(value);
}