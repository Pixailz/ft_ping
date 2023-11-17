/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:44:51 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 08:19:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	free_conf(void)
{
	t_conf	*conf;

	conf = get_conf();
	if (conf->socket >= 0)
		close(conf->socket);
	free(conf);
}

void	free_data(void)
{
	free_conf();
	ft_free_opts();
	if (DEBUG > 0)
		close(DEBUG_FD);
}
