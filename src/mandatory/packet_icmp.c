/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_icmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:14:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/15 01:46:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	ft_fill_hdr_icmp_echo(struct icmphdr *packet, \
												t_uint16 id, t_uint16 sequence)
{
	packet->type = ICMP_ECHO;
	packet->code = 0;
	packet->un.echo.id = htons(id);
	packet->un.echo.sequence = htons(sequence);
	packet->checksum = 0;
}

static void	fill_timestamp(void *buffer)
{
	if (gettimeofday(buffer, NULL) == -1)
		ft_perr("Failed to get time of day");
}

static void	fill_random_data(void *buffer, t_size size)
{
	ft_memset(buffer, 42, size);
}

void	ft_fill_icmp_echo(void *packet, t_uint16 sequence)
{
	fill_random_data(packet + LEN_HDR_ICMP_ECHO, LEN_ICMP_ECHO_PAY);
	fill_timestamp(packet + LEN_HDR_ICMP_ECHO + 4);
	ft_fill_hdr_icmp_echo(packet, 42, sequence);
}
