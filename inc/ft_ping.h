/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/30 05:58:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

#include "libft_memory.h"
#include "libft_print.h"
#include "libft_error.h"

# define DEBUG			1
# define DEBUG_FD		420
# define OPT_SHORT		"v?"

# define	H_ERROR		"[" RED "ERROR" RST "]" SEP

typedef enum e_emode
{
	MALLOC,
}	t_emode;

typedef struct s_err
{
	t_uint32			malloc;
	t_uint32			parse;
}		t_err;

typedef struct s_conf
{
	t_uint32			flag;
}		t_conf;

// PARSE
void	parse_arg(int ac, char **av);
void	parse_arg_short(char *arg);
void	parse_param(char *param);

t_bool	is_arg_short(char *arg);

// SINGLETON
t_err	*get_error(void);
t_conf	*get_conf(void);

// DATASET
void	init_data(void);
void	free_data(void);

#endif //FT_PING_H
