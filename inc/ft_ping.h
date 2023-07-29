/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/29 21:34:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

#include <libft.h>

# define DEBUG			1
# define DEBUG_FD		420


void	parse_arg(int ac, char **av);
void	parse_arg_long(char *arg);
void	parse_arg_short(char *arg);

t_bool	is_arg_long(char *arg);
t_bool	is_arg_short(char *arg);

#endif //FT_PING_H
