/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/31 06:46:16 by brda-sil         ###   ########.fr       */
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

// free.c
void		free_data(void);

// init.c
void		init_data(void);

// main.c
int			main(int ac, char **av);

// arg.c
void		parse_arg(int ac, char **av);

// error.c
void		parse_error(void);

// param.c
void		parse_param(char *param);

// short.c
t_bool		is_arg_short(char *arg);
void		parse_arg_short(char *arg);

// conf.c
t_conf		*get_conf(void);

// error.c
t_err		*get_error(void);
void		set_error_malloc(t_errno value);
void		set_error(t_emode mode, t_errno value);

#endif //FT_PING_H
