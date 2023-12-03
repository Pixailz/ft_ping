/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 06:53:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/03 16:14:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static t_int4	get_ip(char *value)
{
	t_int4	ip_tmp;

	ip_tmp = ft_ipstr(value);
	if (ip_tmp)
		return (ip_tmp);
	ip_tmp = ft_htoi4(value, "443");
	if (ip_tmp)
		return (ip_tmp);
	ip_tmp = ft_htoi4(value, "80");
	if (ip_tmp)
		return (ip_tmp);
	ip_tmp = ft_htoi4(value, "8080");
	return (ip_tmp);
}

static void	reset_stats(t_stats *sts)
{
	sts->send_ts = 0;
	sts->nb_recv = 0;
	sts->nb_trans = 0;
	sts->rtt_min = 0;
	sts->rtt_avg = 0;
	sts->rtt_max = 0;
	sts->rtt_stddev = 0;
}

static void	setup_target(char *value)
{
	t_conf				*conf;
	char				ip_str[INET_ADDRSTRLEN];

	conf = get_conf();
	conf->cur_target.value = value;
	conf->cur_target.ip = ft_htonl(get_ip(value));
	ft_ntop(AF_INET, conf->cur_target.ip, ip_str);
	conf->cur_target.addr = ft_ltoaddr(conf->cur_target.ip);
	conf->sequence = -1;
	ft_hdr_ip_set_dst(conf->cur_target.ip);
	ft_hdr_icmp_seq_inc();
	reset_stats(&conf->stats);
	ft_printf(FMT_STATS_PING, value, ip_str, FT_PING_ICMP_SIZE + PADDING);
	if (ft_optget("verbose")->is_present)
		ft_printf(FMT_STATS_PING_VERBOSE, conf->id_icmp, conf->id_icmp);
	ft_printf("\n");
}

void	process_args(void)
{
	t_opts		*opts;
	t_opt_value	*target;
	t_conf		*conf;

	conf = get_conf();
	opts = ft_get_opts(0);
	target = opts->value;
	conf->begin = ft_getnow_ms();
	while (target)
	{
		setup_target(target->value);
		while (!conf->interrupted && conf->stats.nb_trans != conf->nb_packet)
		{
			ft_ping_run();
			if (ft_getnow_ms() - conf->begin >= conf->timeout * A_SEC)
				break ;
			if (conf->stats.nb_trans != conf->nb_packet)
				usleep(conf->interval * A_SEC);
		}
		print_stats();
		target = target->next;
	}
}
