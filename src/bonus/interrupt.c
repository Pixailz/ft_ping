/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interrupt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:00:02 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/21 04:33:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

void	ft_ping_interrupt(int sig)
{
	t_conf	*conf;

	if (sig != SIGINT)
		return ;
	dprintf(DEBUG_FD, "SIGINT received\n");
	conf = get_conf();
	conf->interrupted = TRUE;
}
