/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse_pattern.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:44:42 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/03 16:13:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

static	int	get_bytes(char c)
{
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = 0;
	if (ft_strchr(BLHEX, c))
		return (ft_atoi_base(tmp, BLHEX));
	else if (ft_strchr(BUHEX, c))
		return (ft_atoi_base(tmp, BUHEX));
	else
	{
		ft_dprintf(2, "%s: error in pattern near %c\n", ft_get_opts(0)->prog_name, \
																			c);
		return (-1);
	}
}

t_bin	post_parse_pattern_custom(t_conf *conf, char *str)
{
	int		counter;
	int		pattern_size;
	char	value;
	char	tmp;

	counter = 0;
	pattern_size = 0;
	while (str[counter] && pattern_size < FT_PING_MAX_ICMP_DATA_SIZE / 2)
	{
		tmp = 0;
		if (str[counter] == ' ')
		{
			counter++;
			continue ;
		}
		tmp = get_bytes(str[counter++]);
		if (tmp == -1)
			return (1);
		value = get_bytes(str[counter++]);
		if (value == -1)
			return (1);
		conf->pattern[pattern_size++] = value | (tmp << 4);
	}
	conf->pattern_size = pattern_size;
	return (0);
}

void	post_parse_icmp_data_custom(t_conf *conf)
{
	int	data_size;

	data_size = 0;
	while (data_size < conf->size)
	{
		if (data_size + conf->pattern_size <= conf->size)
		{
			ft_memcpy(conf->data_icmp + data_size, conf->pattern, \
															conf->pattern_size);
			data_size += conf->pattern_size;
		}
		else
		{
			ft_memcpy(conf->data_icmp + data_size, conf->pattern, \
														conf->size - data_size);
			data_size += conf->size - data_size;
		}
	}
}

void	post_parse_icmp_data_random(t_conf *conf)
{
	int	counter;

	counter = 0;
	while (counter <= conf->size)
		conf->data_icmp[counter++] = ft_randchar();
}

int	post_parse_pattern(t_conf *conf)
{
	t_opt	*opt;

	opt = ft_optget("size");
	if (opt->is_present)
	{
		conf->custom_size = TRUE;
		conf->size = ft_atoll(opt->value->value);
	}
	else
		conf->size = FT_PING_ICMP_SIZE;
	if (conf->size > FT_PING_MAX_ICMP_DATA_SIZE)
	{
		ft_dprintf(2, "%s: option value too big: %d\n", \
										ft_get_opts(0)->prog_name, conf->size);
		return (1);
	}
	opt = ft_optget("pattern");
	ft_bzero(conf->data_icmp, FT_PING_MAX_ICMP_DATA_SIZE);
	if (opt->is_present)
	{
		ft_bzero(conf->pattern, FT_PING_MAX_ICMP_DATA_SIZE / 2);
		if (post_parse_pattern_custom(conf, opt->value->value))
			return (1);
		post_parse_icmp_data_custom(conf);
	}
	else
		post_parse_icmp_data_random(conf);
	return (0);
}
