/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 05:05:03 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/30 05:51:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_conf	*get_conf(void)
{
	static t_conf	*conf = NULL;

	if (conf == NULL)
		conf = (t_conf *)ft_calloc(sizeof(t_conf), 1);
	return (conf);
}
