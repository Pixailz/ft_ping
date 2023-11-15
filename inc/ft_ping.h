/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/15 06:17:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "libft_memory.h"
# include "libft_print.h"
# include "libft_parsing.h"
# include "libft_network/ipv4.h"

# include "netinet/ip_icmp.h"
/*
 ICMP_ECHO
 */

# include "sys/time.h"
/*
 gettimeofday()
 */

# define PROG_NAME			"ft_ping"
# define DEBUG				1
# define VERSION			"0.0.2"

# define PING_TTL			64

/*
 * packet structure :
 *   [ IP header    ]
 *   [ ICMP header  ]
 *   [ ICMP payload ]
 */

# define LEN_HDR_IP			24
# define LEN_HDR_ICMP_ECHO	8
# define LEN_ICMP_ECHO_PAY	56

# define PACKET_SIZE		LEN_HDR_IP + LEN_HDR_ICMP_ECHO + LEN_ICMP_ECHO_PAY

typedef enum e_emode
{
	E_MALLOC = BIT_01,
}	t_emode;

// help.c
void		help_header(void);
void		help_part_1(void);
void		help_part_2(void);
void		help_footer(void);
t_bool		help(void);

// main.c
int			get_socket(void);
void		send_echo(int socket, char *packet, const struct sockaddr *dst);
int			main(void);

// packet_icmp.c
void		ft_fill_hdr_icmp_echo(t_hdr_icmp_echo *packet, \
												t_uint16 id, t_uint16 sequence);
void		ft_fill_icmp_echo(void *packet, t_uint16 sequence);

// packet_ip.c
void		ft_fill_hdr_ip(t_hdr_ip *packet, t_uint32 dst);

// packet_print.c
void		packet_print_iphdr(t_hdr_ip *pkt);
void		packet_print_icmphdr(t_hdr_icmp_echo *pkt);
void		packet_print_icmpdata(void *data);
void		packet_print(void *pkt);
void		packet_print_raw(char *pkt);

// parsing.c
t_bool		is_cmd_opt(t_opt opt);
void		post_parse_cmd_opt(void);
void		parse_opts(int ac, char **av);

// process.c
void		process_args(void);

// usage.c
t_bool		usage(void);
void		try_help_usage(void);
void		unknown_arg(void);

// version.c
t_bool		version(void);

#endif //FT_PING_H
