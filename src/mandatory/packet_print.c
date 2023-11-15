/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:20:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/15 01:41:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

#include <stdio.h>

#define PKT_3 " 0x%01X "
#define PKT_4 "  0x%01X  "
#define PKT_8 "     0x%02X      "
#define PKT_13 "         0x%04X          "
#define PKT_16 "            0x%04X             "
#define PKT_24 "                       0x%06X                        "
#define PKT_32 "                          0x%08X                           "

static const char	*g_pkt_iphdr = \
"Internet Header Format\n" \
" 0                   1                   2                   3\n" \
" 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_4 "|" PKT_4 "|" PKT_8 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_16 "|" PKT_3 "|" PKT_13 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_8 "|" PKT_8 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_32 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_32 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_24 "|" PKT_4 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

static const char	*g_pkt_icmp_header = \
"ICMP: Echo or Echo Reply Message\n" \
" 0                   1                   2                   3\n" \
" 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_8 "|" PKT_8 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_16 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

// void	packet_print_iphdr(struct iphdr *pkt)
// {
// 	printf(g_pkt_iphdr, pkt->version, pkt->internet_header_len,
// 		pkt->type_of_service, pkt->total_len, pkt->identification, pkt->flags,
// 		pkt->fragment_off, pkt->ttl, pkt->proto, pkt->header_checksum,
// 		pkt->src_addr, pkt->dst_addr, pkt->options, pkt->padding);
// }

// void	packet_print_icmphdr(struct icmphdr *pkt)
// {
// 	printf(g_pkt_icmp_header, pkt->type, pkt->code, pkt->checksum,
// 		pkt->identifier, pkt->sequence);
// }

// void	packet_print_icmpdata(void *data)
// {
// 	struct timeval	*tv;

// 	tv = (struct timeval *)(data + 4);
// 	printf("tv.sec %ld\n", tv->tv_sec);
// 	printf("tv.usec %ld\n", tv->tv_usec);
// }

// void	packet_print(void *pkt)
// {
// 	packet_print_iphdr(pkt);
// 	packet_print_icmphdr(pkt + LEN_HDR_IP);
// 	packet_print_icmpdata(pkt + LEN_HDR_IP + LEN_HDR_ICMP_ECHO);
// }

void	packet_print_raw(char *pkt)
{
	t_size	i;

	i = 0;
	while (i < PACKET_SIZE)
	{
		printf("%02X", (unsigned char)pkt[i]);
		i++;
		if (i % 4 == 0)
			printf("\n");
	}
}
