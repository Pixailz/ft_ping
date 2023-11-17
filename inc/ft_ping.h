/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 10:17:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

// # define NO_ANSI

# include "libft_memory.h"
# include "libft_print.h"
# include "libft_parsing.h"
# include "libft_network/ipv4.h"

# include <errno.h>
/*
 errno
 */

# include <signal.h>
/*
 SIGALRM
 SIG_ERR
 getuid()
 */

# include <unistd.h>
/*
 getpid()
 getuid()
 */

# include <stdio.h>
/*
 printf()
 dprintf()
 */

# include <arpa/inet.h>
/*
 inet_ntop()
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

# include "fmt.h"

# define PROG_NAME				"ft_ping"
# define DEBUG					1
# define VERSION				"1.1.0"

// Time To Live of the iphdr
# define FT_PING_TTL			64
// Number of packet to send
# define FT_PING_PKT_N			2
// Interval, in sec, between each packet
# define FT_PING_PKT_INTERVAL	1
// Timeout, in sec, before aborting
# define FT_PING_TIMEOUT_RECV	2

// Identification of the iphdr
# define FT_PING_IP_ID			420

/*
 * packet structure :
 *   [ IP header    ]
 *   [ ICMP header  ]
 *   [ ICMP payload ]
 */

# define FT_PING_USE_IP_OPTS	FALSE

# if FT_PING_USE_IP_OPTS == 1

#  define LEN_HDR_IP			24

# else

#  define LEN_HDR_IP			20

# endif // FT_PING_USE_IP_OPTS == 1

# define LEN_HDR_ICMP_ECHO		8
# define PADDING				8
# define LEN_ICMP_ECHO_PAY		48

# define PACKET_SIZE LEN_HDR_IP + LEN_HDR_ICMP_ECHO + PADDING + LEN_ICMP_ECHO_PAY

# define MAX_PACKET_SIZE		0x200

// MASK
# define IPHDR_M_IHL			0x0F
# define IPHDR_M_VERSION		0xF0
# define IPHDR_M_FRAG_OFF		0x1FFF
# define IPHDR_M_FLAGS			0xE000
# define IPHDR_M_OPTIONS		0xF000
# define IPHDR_M_PADDING		0x000F

// IPHDR OPTIONS
# define IPHDR_F_DONT_FRAG		0x2
# define IPHDR_F_MORE_FRAG		0x1

typedef suseconds_t				t_ts;

typedef struct __attribute__((__packed__)) s_iphdr
{
# if __BYTE_ORDER == __LITTLE_ENDIAN

	t_uint8		ihl:4;
	t_uint8		version:4;

# elif __BYTE_ORDER == __BIG_ENDIAN

	t_uint8		version:4;
	t_uint8		ihl:4;

# endif // __BYTE_ORDER == __LITTLE_ENDIAN
	t_uint8		tos;
	t_uint16	total_len;

	t_uint16	identification;
	t_uint16	fragment_off;

	t_uint8		ttl;
	t_uint8		protocol;
	t_uint16	checksum;

	t_uint32	src_addr;
	t_uint32	dst_addr;

# if FT_PING_USE_IP_OPTS == 1

#  if __BYTE_ORDER == __LITTLE_ENDIAN

	t_uint32	options:24;
	t_uint32	padding:8;

#  elif __BYTE_ORDER == __BIG_ENDIAN

	t_uint32	padding:8;
	t_uint32	options:24;

#  endif // __BYTE_ORDER == __LITTLE_ENDIAN

# endif // FT_PING_USE_IP_OPTS == 1

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

typedef struct s_stats
{
	t_ts		send_ts;
	t_uint16	nb_recv;
	t_uint16	nb_err;
	t_uint16	nb_trans;
	t_ts		rtt_min;
	t_ts		rtt_avg;
	t_ts		rtt_max;
	t_ts		rtt_stddev;
}	t_stats;

typedef struct s_conf
{
	int			socket;

	t_uint16	id_icmp;
	t_uint16	sequence;

	t_target	cur_target;

	char		packet[PACKET_SIZE];

	t_stats		stats;
}	t_conf;

/* ########################################################################## */
/* FILES */
/* ##### */

// cmd/help.c
void		help_header(void);
void		help_part_1(void);
void		help_part_2(void);
void		help_footer(void);
t_bool		help(void);

// cmd/usage.c
t_bool		usage(void);
void		try_help_usage(void);
void		unknown_arg(void);

// cmd/version.c
t_bool		version(void);

// data/conf.c
t_conf		*get_conf(void);

// data/free.c
void		free_conf(void);
void		free_data(void);

// data/init.c
t_bin		init_config(void);
t_bin		init_socket(void);
t_bin		init_packet(void);
t_bin		init_signal(void);

// data/parsing.c
t_bool		is_cmd_opt(t_opt opt);
void		post_parse_cmd_opt(void);
t_bin		parse_opts(int ac, char **av);

// main.c
void		ft_ping(int ac, char **av);
int			main(int ac, char **av);

// packet/checksum.c
t_uint16	ft_checksum(char *data, t_size size);

// packet/icmp.c
void		ft_fill_hdr_icmp(t_icmphdr_echo *packet);
void		ft_hdr_icmp_seq_inc(void);
void		ft_hdr_icmp_echo_fill(void *packet);

// packet/ip.c
void		ft_hdr_ip_set_dst(t_int4 dst);
void		ft_hdr_ip_fill(t_iphdr *packet);

// packet/print.c
void		packet_print_iphdr(t_iphdr *pkt);
void		packet_print_iphdr(t_iphdr *pkt);
void		packet_print_icmphdr(t_icmphdr_echo *pkt);
void		packet_print_icmpdata(void *data);
void		packet_print(void *pkt);
void		packet_print_raw(char *pkt, t_size size);

// process.c
void		process_args(void);

// recv_pong.c
void		recv_pong(void);

// run.c
void		ft_ping_run(__attribute__((unused)) int sig);

// send_ping.c
void		send_ping(const struct sockaddr *dst);

// socket.c
int			ft_create_sock_echo(void);

// stats/print.c
void		print_pong_stats(char *pkt, t_icmphdr_echo *icmphdr_echo);
char		*get_color_pkt_loss(int pkt_loss);
void		print_rtt(t_stats sts, int pkt_recv);
void		print_stats(void);

// stats/rtt.c
t_ts		ft_getnow_ms(void);
void		update_stats_rtt(t_ts rtt, t_uint16 sequence);

/* ########################################################################## */

#endif //FT_PING_H
