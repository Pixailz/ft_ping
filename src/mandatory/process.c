/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 06:53:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 08:08:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static	t_int4	get_ip(char *value)
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

void	process_args(void)
{
	t_opts		*opts;
	t_opt_value	*ptr;
	t_int4		tmp_ip;

	opts = ft_get_opts(0);
	ptr = opts->value;
	while (ptr)
	{
		tmp_ip = get_ip(ptr->value);
		ft_putip_fd(tmp_ip, 1);
		ft_putstr_fd("\n", 1);
		ptr = ptr->next;
	}
}
