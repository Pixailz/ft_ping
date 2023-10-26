/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:21:19 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/27 01:01:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bin	init_data(void)
{
	if (!get_error())
		return (ft_perr("malloc" SEP "failed to malloc t_err\n", BIT_01));
	if (!get_conf())
		return (ft_perr("malloc" SEP "failed to malloc t_conf\n", BIT_02));
	return (BIT_00);
}
