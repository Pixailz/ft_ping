/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:53:21 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/06 12:35:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static t_uint16	get_fragment_off(t_uint8 flags, t_uint16 get_fragment_off)
{
	t_uint16	r;

	r = flags << 13;
	r |= get_fragment_off & IPHDR_M_FRAG_OFF;
	return (r);
}

void	ft_hdr_ip_set_dst(t_int4 dst)
{
	static t_conf	*conf = FT_NULL;
	static t_iphdr	*pkt = FT_NULL;

	if (!conf)
	{
		conf = get_conf();
		pkt = (t_iphdr *)conf->packet;
	}
	pkt->dst_addr = dst;
}

void	ft_hdr_ip_fill(t_iphdr *packet)
{
	packet->version = 4;
	packet->ihl = LEN_HDR_IP / 4;
	packet->tos = 0;
	packet->total_len = ft_htons(PACKET_SIZE);
	packet->identification = ft_htons(FT_PING_IP_ID);
	packet->fragment_off = ft_htons(get_fragment_off(IPHDR_F_DONT_FRAG, 0));
	packet->ttl = FT_PING_TTL;
	packet->protocol = IPPROTO_ICMP;
	packet->checksum = 0;
	packet->src_addr = INADDR_ANY;
	packet->dst_addr = 0;
# if FT_PING_USE_IP_OPTS == 1
	packet->options = ft_htons(0);
	packet->padding = 0;
# endif // FT_PING_USE_IP_OPTS == 1
	ft_pdeb("iphdr: packet len %d\n", sizeof(*packet));
}
