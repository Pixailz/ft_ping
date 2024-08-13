/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:44:51 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 21:10:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	free_conf(void)
{
	t_conf	*conf;

	conf = get_conf();
	if (conf->socket >= 0)
		close(conf->socket);
	free(conf->pattern);
	free(conf->data_icmp);
	free(conf);
}

void	free_data(void)
{
	free_conf();
}
