/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 06:53:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 00:42:46 by brda-sil         ###   ########.fr       */
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

	conf = get_conf();
	conf->cur_target.value = value;
	ft_memset(&addr, 0, sizeof(struct sockaddr_in));
	conf->cur_target.ip = ft_htonl(get_ip(value));
	ft_hdr_ip_set_dst(conf->cur_target.ip);
	addr.sin_addr.s_addr = conf->cur_target.ip;
	conf->cur_target.addr = *((struct sockaddr *)&addr);
	conf->sequence = 0;
}

void	process_args(void)
{
	t_opts		*opts;
	t_opt_value	*target;

	opts = ft_get_opts(0);
	target = opts->value;
	while (target)
	{
		setup_target(target->value);
		ft_send_echo();
		target = target->next;
	}
}
