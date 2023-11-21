/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:04:24 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/21 04:33:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping_bonus.h"

t_uint16	ft_checksum(char *data, t_size size)
{
	t_uint32	sum;
	t_size		i;

	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += ft_ntohs(*((t_uint16 *)(data + i)));
		if (sum >> 16)
			sum -= 0xffff;
		i += 2;
	}
	if (size & 1)
	{
		sum += ft_ntohs(*((t_uint16 *)(data + size - 1)));
		if (sum > 0xffff)
			sum -= 0xffff;
	}
	return (ft_htons(~sum));
}
