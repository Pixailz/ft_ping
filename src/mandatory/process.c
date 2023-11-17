/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 06:53:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 07:52:32 by brda-sil         ###   ########.fr       */
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

static void	setup_target(char *value)
{
	t_conf				*conf;
	struct sockaddr_in	addr;
	char				ip_str[INET_ADDRSTRLEN];

	conf = get_conf();
	conf->cur_target.value = value;
	ft_memset(&addr, 0, sizeof(struct sockaddr_in));
	conf->cur_target.ip = ft_htonl(get_ip(value));
	ft_ntop(AF_INET, conf->cur_target.ip, ip_str);
	ft_hdr_ip_set_dst(conf->cur_target.ip);
	addr.sin_addr.s_addr = conf->cur_target.ip;
	conf->cur_target.addr = *((struct sockaddr *)&addr);
	conf->sequence = -1;
	ft_hdr_icmp_seq_inc();
	ft_memset(&conf->stats, 0, sizeof(conf->stats));
	printf(FMT_STATS_PING, value, ip_str, LEN_ICMP_ECHO_PAY + PADDING);
}

void	process_args(void)
{
	t_opts		*opts;
	t_opt_value	*target;
	t_conf		*conf;

	conf = get_conf();
	opts = ft_get_opts(0);
	target = opts->value;
	while (target)
	{
		setup_target(target->value);
		while (conf->stats.nb_trans != FT_PING_PKT_N)
		{
			ft_ping_run(0);
			if (conf->stats.nb_trans != FT_PING_PKT_N)
				usleep(FT_PING_PKT_INTERVAL * 1000000);
		}
		print_stats();
		target = target->next;
	}
}
