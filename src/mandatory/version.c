/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   version.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 06:03:14 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 06:59:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bool	version(void)
{
	ft_printf(PROG_NAME " (ft_libft) %s\n\n", VERSION);
	ft_putendl_fd("Written by Pixailz", 1);
	return (TRUE);
}
