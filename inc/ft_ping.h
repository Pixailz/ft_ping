/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/27 02:57:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "libft_memory.h"
# include "libft_print.h"
# include "libft_parsing.h"

# define DEBUG			1
# define VERSION		"0.0.1"

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

// help.c
void		unknown_arg(char *prog_path);
t_bool		version(void);
t_bool		usage(void);
t_bool		help(void);

// init.c
t_bin		init_data(void);

// main.c
int			main(int ac, char **av);

// parsing.c
t_bool		post_parse_opt(t_opt opt);
void		post_parse(char *prog_path);
void		parse_arg(int ac, char **av);

// singleton/conf.c
t_conf		*get_conf(void);

// singleton/error.c
t_err		*get_error(void);
void		set_error_malloc(t_bin value);
void		set_error(t_emode mode, t_bin value);

#endif //FT_PING_H
