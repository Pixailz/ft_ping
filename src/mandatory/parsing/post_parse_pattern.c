/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse_pattern.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:44:42 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/06 12:10:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	post_parse_icmp_data_random(t_conf *conf)
{
	int	counter;

	counter = 0;
	while (counter < FT_PING_ICMP_SIZE)
		conf->data_icmp[counter++] = ft_randchar();
}

int	post_parse_pattern(t_conf *conf)
{
	ft_bzero(conf->data_icmp, FT_PING_ICMP_SIZE);
	post_parse_icmp_data_random(conf);
	return (0);
}
