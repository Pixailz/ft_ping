/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/27 01:03:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "libft_memory.h"
# include "libft_print.h"
# include "libft_parsing.h"

# define DEBUG			1
# define DEBUG_FD		420
# define OPT_SHORT		"v?"

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
t_bin		init_data(void);

// main.c
int			main(int ac, char **av);

// parsing.c
void		parse_arg(int ac, char **av);

// singleton/conf.c
t_conf		*get_conf(void);

// singleton/error.c
t_err		*get_error(void);
void		set_error_malloc(t_bin value);
void		set_error(t_emode mode, t_bin value);

#endif //FT_PING_H
