/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 06:02:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 05:18:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bin	usage(void)
{
	ft_printf("\
Usage: %s [-v?V] [-c NUMBER] [-w N] [-W N] [--count=NUMBER] [--verbose]\n\
            [--timeout=N] [--linger=N] [--help] [--usage] [--version]\n\
            HOST ...\n", PROG_NAME);
	return (0);
}
