/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 21:10:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

// # define ANSI_NO_COLOR
# define PROG_NAME				"ft_ping"
# ifndef DEBUG
#  define DEBUG					1
# endif //DEBUG

# include "libft_memory.h"
# include "libft_print.h"
# include "libft_parsing.h"
# include "libft_network/ipv4.h"
# include "libft_network/packet.h"
# include "libft_random.h"

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
 sprintf()
 */

# include <netinet/ip_icmp.h>
/*
 ICMP_ECHO
 */

# include <sys/time.h>
/*
 gettimeofday()
 */

# include <math.h>
/*
 sqrt()
 */

# include "fmt_stats.h"

// Identification of the iphdr
# define FT_PING_IP_ID					420
# define FT_PING_MAX_ICMP_DATA_SIZE		0xff00

/*
 * packet structure :
 *   [ IP header    ]
 *   [ ICMP header  ]
 *   [ ICMP payload ]
 */

# define PADDING						8

# define FT_PING_ICMP_SIZE				48
// Number of packet to send
// -c
# define FT_PING_NB_PKT					-1
// Second of time execution allowed
// -w
# define FT_PING_TIMEOUT				64
// Second to set SO_RCVTIMEO And second before recvmsg receive SIGALRM
// -W
# define FT_PING_LINGER					10
// Time To Live of the iphdr
// --ttl
# define FT_PING_TTL					64
// Interval, in sec, between each packet
// -i
# define FT_PING_INTERVAL				1

typedef suseconds_t						t_ts;

typedef struct s_target
{
	char			*value;
	t_int4			ip;
	struct sockaddr	addr;
}	t_target;

# define NB_STATS	0xffff

typedef struct s_stats
{
	t_ts		send_ts;
	t_uint16	nb_recv;
	t_uint16	nb_err;
	t_uint16	nb_trans;
	t_ts		rtts[NB_STATS];
	t_ts		rtt_min;
	t_ts		rtt_avg;
	t_ts		rtt_max;
}	t_stats;

typedef struct s_conf
{
	int			socket;

	t_int32		nb_packet;
	t_int32		timeout;
	t_int32		linger;
	t_int32		interval;
	t_int32		ttl;
	t_bool		flood;
	t_int32		current_preload;
	t_int32		preload;
	t_bool		custom_size;
	t_int32		size;
	char		*pattern;
	t_int32		pattern_size;
	char		*data_icmp;
	t_uint16	tos;

	t_ts		begin;

	t_uint16	id_icmp;
	t_int32		sequence;

	t_target	cur_target;

	t_packet	packet;

	t_stats		stats;

	t_bool		interrupted;
}	t_conf;

# define A_SEC					1000000

/* ########################################################################## */
/* FILES */
/* ##### */

// cmd/help.c

void	help_header(void);
void	help_part_1(void);
void	help_part_2(void);
void	help_footer(void);
t_bin	help(void);

// cmd/usage.c

t_bin	usage(void);

// data/conf.c

t_conf	*get_conf(void);

// data/free.c

void	free_conf(void);
void	free_data(void);

// data/init.c

t_bin	init_config(void);
int		ft_create_sock_echo(int *sock);
t_bin	init_socket(void);
t_bin	init_packet(void);
t_bin	init_signal(void);

// error.c

void	print_icmp_errn(t_uint16 seq, t_uint16 tot_len, t_int32 errn);
void	print_icmp_timeout(void);
void	print_icmp_error(unsigned char *pkt);

// interrupt.c

void	ft_ping_interrupt(int sig);

// main.c

t_bin	ft_ping(int ac, char **av);
int		main(int ac, char **av);

// packet/get_packet_size.c

t_size	get_packet_size(void);
t_size	get_icmp_size(void);

// packet/icmp.c

void	ft_fill_hdr_icmp(t_icmphdr_echo *packet);
void	ft_hdr_icmp_seq_inc(void);
void	ft_hdr_icmp_echo_fill(void *packet);

// packet/ip.c

void	ft_hdr_ip_set_dst(t_int4 dst);
void	ft_hdr_ip_fill(t_iphdr *packet);

// packet/print.c

void	packet_print_icmpdata(void *data);
void	packet_print(void *pkt);

// parsing/parse.c

t_bin	parse_opts(int ac, char **av);

// parsing/post_parse.c

t_bool	post_parse_incompatible_opt(void);
t_bin	post_parse(void);

// parsing/post_parse_conf_1.c

void	post_parse_count(t_conf *conf);
void	post_parse_timeout(t_conf *conf);
void	post_parse_linger(t_conf *conf);
void	post_parse_interval(t_conf *conf);
void	post_parse_ttl(t_conf *conf);

// parsing/post_parse_conf_2.c

void	post_parse_preload(t_conf *conf);
void	post_parse_tos(t_conf *conf);

// parsing/post_parse_pattern.c

t_bin	post_parse_pattern_custom(t_conf *conf, char *str);
void	post_parse_icmp_data_custom(t_conf *conf);
void	post_parse_icmp_data_random(t_conf *conf);
int		post_parse_pattern(t_conf *conf);

// process.c

void	process_args(void);

// recv_pong.c

void	recv_pong(void);

// run.c

void	ft_ping_run(void);

// send_ping.c

t_bool	send_ping(const struct sockaddr *dst);

// stats/print.c

void	print_pong_stats(unsigned char *pkt, t_icmphdr_echo *icmphdr_echo);
char	*get_color_pkt_loss(int pkt_loss);
t_ts	rtt_get_standard_deviation(t_stats sts, int pkt_recv, t_ts rtt_avg);
void	print_rtt(t_stats sts, int pkt_recv);
void	print_stats(void);

// stats/rtt.c

t_ts	ft_getnow_ms(void);
void	update_stats_rtt(t_ts rtt, t_uint16 sequence);

/* ########################################################################## */

#endif //FT_PING_H
