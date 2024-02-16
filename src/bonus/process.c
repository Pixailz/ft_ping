/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 06:53:08 by brda-sil          #+#    #+#             */
/*   Updated: 2024/02/16 15:07:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

static t_bool	get_ip(t_conf *conf, char *value)
{
	t_int4	ip_tmp;

	if (!ft_strncmp(value, "0.0.0.0", 7))
	{
		conf->cur_target.ip = 0;
		return (FALSE);
	}
	ip_tmp = ft_ipstr(value);
	if (ip_tmp)
	{
		conf->cur_target.ip = ip_tmp;
		return (FALSE);
	}
	ip_tmp = ft_htoi4(value, "443");
	if (ip_tmp)
	{
		conf->cur_target.ip = ip_tmp;
		return (FALSE);
	}
	ip_tmp = ft_htoi4(value, "80");
	if (ip_tmp)
	{
		conf->cur_target.ip = ip_tmp;
		return (FALSE);
	}
	ip_tmp = ft_htoi4(value, "8080");
	if (ip_tmp)
	{
		conf->cur_target.ip = ip_tmp;
		return (FALSE);
	}
	dprintf(2, "%s: unknown host\n", ft_get_opts(0)->prog_name);
	return (TRUE);
}

static void	reset_stats(t_stats *sts)
{
	sts->send_ts = 0;
	sts->nb_recv = 0;
	sts->nb_trans = 0;
	sts->rtt_min = 0;
	sts->rtt_avg = 0;
	sts->rtt_max = 0;
}

static t_bool	setup_target(t_conf *conf, char *value)
{
	char				ip_str[INET_ADDRSTRLEN];

	conf->cur_target.value = value;
	if (get_ip(conf, value))
		return (TRUE);
	conf->cur_target.ip = ft_htonl(conf->cur_target.ip);
	ft_ntop(AF_INET, conf->cur_target.ip, ip_str);
	conf->cur_target.addr = ft_ltoaddr(conf->cur_target.ip);
	conf->sequence = -1;
	ft_hdr_ip_set_dst(conf->cur_target.ip);
	ft_hdr_icmp_seq_inc();
	reset_stats(&conf->stats);
	if (conf->custom_size)
		ft_printf(FMT_STATS_PING, value, ip_str, conf->size);
	else
		ft_printf(FMT_STATS_PING, value, ip_str, conf->size + PADDING);
	if (ft_optget("verbose")->is_present)
		ft_printf(FMT_STATS_PING_VERBOSE, conf->id_icmp, conf->id_icmp);
	ft_printf("\n");
	conf->current_preload = conf->preload;
	return (FALSE);
}

void	process_args(void)
{
	t_opt_value	*target;
	t_conf		*conf;

	conf = get_conf();
	target = ft_get_opts(0)->value;
	conf->begin = ft_getnow_ms();
	while (target)
	{
		if (setup_target(conf, target->value))
		{
			conf->stats.nb_err = 1;
			return ;
		}
		while (!conf->interrupted && conf->stats.nb_trans != conf->nb_packet)
		{
			ft_ping_run();
			if (ft_getnow_ms() - conf->begin >= conf->timeout * A_SEC)
				break ;
			if (conf->current_preload)
			{
				conf->current_preload--;
				continue ;
			}
			if (conf->stats.nb_trans != conf->nb_packet)
				usleep(conf->interval * A_SEC);
		}
		print_stats();
		target = target->next;
	}
}
