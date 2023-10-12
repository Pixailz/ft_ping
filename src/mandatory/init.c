/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:21:19 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/12 20:25:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_errno	init_data(void)
{
	if (!get_error())
		return (ft_perr("malloc" SEP "failed to malloc t_err\n", ERRN_01));
	if (!get_conf())
		return (ft_perr("malloc" SEP "failed to malloc t_conf\n", ERRN_02));
	return (ERRN_00);
}
