/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:20:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 23:48:57 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	packet_print_icmpdata(void *data)
{
	ft_pkt_print_icmp(data + PACK_LEN_IP);
	if (DEBUG)
		dprintf(DEBUG_FD, "payload \n");
	ft_pkt_print_raw(data + PADDING, get_conf()->size);
}

void	packet_print(void *pkt)
{
	ft_dprintf(DEBUG_FD, "%s", FMT_BIN_BAR);
	ft_pkt_print_ip(pkt);
	packet_print_icmpdata(pkt + PACK_LEN_IP + PACK_LEN_ICMP_ECHO);
}
