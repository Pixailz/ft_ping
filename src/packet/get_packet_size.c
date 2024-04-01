/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_packet_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:20:55 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 04:53:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_size	get_packet_size(void)
{
	return (LEN_HDR_IP + get_icmp_size());
}

t_size	get_icmp_size(void)
{
	t_conf	*conf;

	conf = get_conf();
	return (LEN_HDR_ICMP_ECHO + PADDING + conf->size);
}
