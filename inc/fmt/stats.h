/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:49:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/05 23:17:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_STATS_H
# define FMT_STATS_H

# define C_MS_MIN		GRE
# define C_MS_AVG		ORA
# define C_MS_MAX		RED
# define C_MS_STDDEV	PUR

# define FMT_MS "%ld.%03ld"

# define FMT_STATS_TRANS \
"--- " C_VALUE "%s" RST " ping statistics ---\n" \
UND BOL YEL "%d" RST " packets transmitted, " \
UND BOL GRE "%d" RST " packets received, " UND BOL "%s%d" RST "%% packet loss\n"

# define FMT_STATS_RTT \
"round-trip " \
C_MS_MIN "min" RST "/" C_MS_AVG "avg" RST "/" \
C_MS_MAX "max" RST "/" C_MS_STDDEV "stddev" RST " = " \
C_MS_MIN FMT_MS RST "/" C_MS_AVG FMT_MS RST "/" \
C_MS_MAX FMT_MS RST "/" C_MS_STDDEV FMT_MS RST " ms\n"

# define FMT_STATS_PING \
"PING " C_VALUE "%s" RST " (" C_IP "%s" RST "): " \
C_SIZE "%d" RST " data bytes"

# define FMT_STATS_PING_VERBOSE \
", id 0x" ITA ORA "%04x" RST " = " ITA ORA "%d" RST

# define FMT_STATS_PONG \
C_SIZE "%d" RST " bytes from " C_IP "%s" RST ": " \
"icmp_seq=" ITA GRE "%d" RST " \
ttl=" ITA GRE "%d" RST " \
time=" YEL FMT_MS RST " ms\n"

# define FMT_STATS_PONG_ERR \
C_SIZE "%d" RST " bytes from " C_VALUE "%s" RST " (" C_IP "%s" RST ")" \
" icmp_seq=" ITA RED "%d" RST ": " \
ORA "%s" RST "\n"

# define FMT_STATS_PONG_TIMEOUT \
"Timeout from " C_VALUE "%s" RST " (" C_IP "%s" RST "):" \
" icmp_seq=" ITA RED "%d" RST "\n"

#endif // FMT_STATS_H
