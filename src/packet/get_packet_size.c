/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_packet_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:20:55 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/11 20:09:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_size	get_packet_size(void)
{
	return (PACK_LEN_IP + get_icmp_size());
}

t_size	get_icmp_size(void)
{
	t_conf	*conf;

	conf = get_conf();
	return (PACK_LEN_ICMP_ECHO + ICMP_HDR_PADDING + conf->size);
}
