/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_ip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:53:21 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/15 01:48:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	ft_fill_hdr_ip(struct iphdr *packet, t_uint32 dst)
{
	packet->version = 4;
	packet->ihl = LEN_HDR_IP / 4;
	packet->tos = 0;
	packet->tot_len = PACKET_SIZE;
	packet->id = 0;
	packet->frag_off = 0;
	packet->ttl = PING_TTL;
	packet->protocol = IPPROTO_COMP;
	packet->check = 0;
	packet->saddr = 1;
	packet->daddr = dst;
}
