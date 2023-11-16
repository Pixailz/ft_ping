/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   version.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 06:03:14 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/16 21:18:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bool	version(void)
{
	printf(PROG_NAME " (ft_libft) %s\n\nWritten by Pixailz\n", VERSION);
	return (TRUE);
}