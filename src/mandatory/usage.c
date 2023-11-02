/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 06:02:30 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/29 18:14:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_bool	usage(void)
{
	ft_putendl_fd("\
Usage: ping [-v?V] [-c NUMBER] [-w N] [-W N] [--count=NUMBER] [--verbose]\n\
            [--timeout=N] [--linger=N] [--help] [--usage] [--version]\n\
            HOST ...", 1);
	return (TRUE);
}
