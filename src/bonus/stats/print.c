/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:58:51 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 20:43:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

void	print_pong_stats(char *pkt, t_icmphdr_echo *icmphdr_echo)
{
	t_iphdr			*iphdr;
	t_conf			*conf;
	t_ts			rtt;
	char			ip_str[INET_ADDRSTRLEN];

	conf = get_conf();
	ft_ntop(AF_INET, conf->cur_target.ip, ip_str);
	rtt = ft_getnow_ms() - conf->stats.send_ts;
	update_stats_rtt(rtt, icmphdr_echo->sequence);
	iphdr = (t_iphdr *)pkt;
	if (!conf->flood && !ft_optget("quiet")->is_present)
		printf(FMT_STATS_PONG, \
			ft_htons(iphdr->total_len) - (LEN_HDR_IP + \
				(conf->custom_size * PADDING)), \
			ip_str, \
			ft_htons(icmphdr_echo->sequence), \
			iphdr->ttl, \
			rtt / 1000, \
			rtt % 1000);
	dprintf(DEBUG_FD, "Received packet\n");
	packet_print(pkt);
}

char	*get_color_pkt_loss(int pkt_loss)
{
	if (pkt_loss < 25)
		return (GRE);
	else if (pkt_loss < 50)
		return (YEL);
	else if (pkt_loss < 75)
		return (ORA);
	else if (pkt_loss <= 100)
		return (RED);
	return (PUR);
}

void	print_rtt(t_stats sts, int pkt_recv)
{
	t_ts	rtt_avg;

	rtt_avg = sts.rtt_avg / pkt_recv;
	printf(FMT_STATS_RTT, \
		sts.rtt_min / 1000, sts.rtt_min % 1000, \
		rtt_avg / 1000, rtt_avg % 1000, \
		sts.rtt_max / 1000, sts.rtt_max % 1000, \
		sts.rtt_stddev / 1000, sts.rtt_stddev % 1000);
}

void	print_stats(void)
{
	t_conf	*conf;
	t_stats	sts;
	int		pkt_loss;

	conf = get_conf();
	sts = conf->stats;
	dprintf(DEBUG_FD, "nb_err %d\n", sts.nb_err);
	if (sts.nb_trans)
		pkt_loss = 100 - ((sts.nb_recv * 100) / sts.nb_trans);
	else
		pkt_loss = 100;
	printf(FMT_STATS_TRANS, \
		conf->cur_target.value, \
		sts.nb_trans, sts.nb_recv, get_color_pkt_loss(pkt_loss), pkt_loss);
	if (pkt_loss != 100)
		print_rtt(sts, sts.nb_recv);
}
