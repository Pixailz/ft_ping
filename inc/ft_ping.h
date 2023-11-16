/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 00:46:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "libft_memory.h"
# include "libft_print.h"
# include "libft_parsing.h"
# include "libft_network/ipv4.h"

# include <stdio.h>
/*
 printf()
 dprintf()
 */

# include <netinet/ip_icmp.h>
/*
 ICMP_ECHO
 */

# include <netinet/in.h>
/*
 htons()
 */

# include <sys/time.h>
/*
 gettimeofday()
 */

# define PROG_NAME			"ft_ping"
# define DEBUG				1
# define VERSION			"0.1.0"

# define FT_PING_IP_ID		420
# define FT_PING_TTL		64

/*
 * packet structure :
 *   [ IP header    ]
 *   [ ICMP header  ]
 *   [ ICMP payload ]
 */

# define LEN_HDR_IP			24
# define LEN_HDR_ICMP_ECHO	8
# define LEN_TIMEVAL		8
# define LEN_ICMP_ECHO_PAY	24

# define PACKET_SIZE		LEN_HDR_IP + \
							LEN_HDR_ICMP_ECHO + \
							LEN_TIMEVAL + \
							LEN_ICMP_ECHO_PAY
# define MAX_PACKET_SIZE	0x

// MASK
# define IPHDR_M_IHL		0x0F
# define IPHDR_M_VERSION	0xF0
# define IPHDR_M_FRAG_OFF	0x1FFF
# define IPHDR_M_FLAGS		0xE000
# define IPHDR_M_OPTIONS	0xF000
# define IPHDR_M_PADDING	0x000F

// IPHDR OPTIONS
# define IPHDR_F_DONT_FRAG	0x2
# define IPHDR_F_MORE_FRAG	0x1

typedef struct __attribute__((__packed__)) s_iphdr
{
	t_uint8		ihl:4;
	t_uint8		version:4;
	t_uint8		tos;
	t_uint16	total_len;

	t_uint16	identification;
	t_uint16	fragment_off;

	t_uint8		ttl;
	t_uint8		protocol;
	t_uint16	checksum;

	t_uint32	src_addr;
	t_uint32	dst_addr;

	t_uint32	options:24;
	t_uint32	padding:8;
}	t_iphdr;

typedef struct __attribute__((__packed__)) s_icmphdr_echo
{
	t_uint8		type;
	t_uint8		code;
	t_uint16	checksum;

	t_uint16	identifier;
	t_uint16	sequence;

}	t_icmphdr_echo;

typedef struct s_target
{
	char			*value;
	t_int4			ip;
	struct sockaddr	addr;
}	t_target;

typedef struct s_conf
{
	int			socket;

	t_uint16	sequence;

	t_target	cur_target;

	char		packet[PACKET_SIZE];
}	t_conf;

// checksum.c
t_uint16	ft_checksum(char *data, t_size size);

// conf.c
t_conf		*get_conf(void);

// free.c
void		free_conf(void);
void		free_data(void);

// help.c
void		help_header(void);
void		help_part_1(void);
void		help_part_2(void);
void		help_footer(void);
t_bool		help(void);

// init.c
t_bin		init_config(void);
t_bin		init_socket(void);
t_bin		init_packet(void);

// main.c
void		ft_ping(int ac, char **av);
int			main(int ac, char **av);

// packet_icmp.c
void		ft_fill_hdr_icmp(t_icmphdr_echo *packet, t_uint16 id);
void		ft_hdr_icmp_seq_inc(void);
void		ft_hdr_icmp_echo_fill(void *packet);

// packet_ip.c
void		ft_hdr_ip_set_dst(t_int4 dst);
void		ft_hdr_ip_fill(t_iphdr *packet);

// packet_print.c
void		packet_print_iphdr(t_iphdr *pkt);
void		packet_print_icmphdr(t_icmphdr_echo *pkt);
void		packet_print_icmpdata(void *data);
void		packet_print(void *pkt);
void		packet_print_raw(char *pkt);

// parsing.c
t_bool		is_cmd_opt(t_opt opt);
void		post_parse_cmd_opt(void);
t_bin		parse_opts(int ac, char **av);

// ping_echo.c
void		ft_send_echo(void);

// process.c
void		process_args(void);

// socket.c
int			ft_create_sock_echo(void);

// usage.c
t_bool		usage(void);
void		try_help_usage(void);
void		unknown_arg(void);

// version.c
t_bool		version(void);

#endif //FT_PING_H
