/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:08:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/03 16:13:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

# include "fmt/icmp.h"

void	print_icmp_errn(t_uint16 seq, t_uint16 tot_len, t_int32 errn)
{
	t_conf			*conf;
	char			ip_str[INET_ADDRSTRLEN];
	const char		*err_str;

	conf = get_conf();
	if (errn < 19)
		err_str = ICMP_RESP[errn];
	else
		err_str = FT_NULL;
	ft_ntop(AF_INET, conf->cur_target.ip, ip_str);
	ft_printf(FMT_STATS_PONG_ERR, \
		ft_htons(tot_len) - LEN_HDR_IP, \
		conf->cur_target.value, ip_str, seq, err_str);
}

void	print_icmp_timeout(void)
{
	t_conf			*conf;
	char			ip_str[INET_ADDRSTRLEN];

	conf = get_conf();
	ft_ntop(AF_INET, conf->cur_target.ip, ip_str);
	ft_printf(FMT_STATS_PONG_TIMEOUT, conf->cur_target.value, ip_str, \
																conf->sequence);
}

void	print_icmp_error(char *pkt)
{
	t_iphdr			*iphdr;
	t_icmphdr_echo	*icmphdr_echo;

	iphdr = (t_iphdr *)pkt;
	icmphdr_echo = (t_icmphdr_echo *)(pkt + LEN_HDR_IP);
	if (icmphdr_echo->type < 19)
		print_icmp_errn(icmphdr_echo->sequence, iphdr->total_len, \
															icmphdr_echo->type);
}
