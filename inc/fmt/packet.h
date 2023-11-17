/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:49:35 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 08:38:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKET_H
# define PACKET_H

# define PKT_V_PREFIX "0x"
# define PKT_V_FMT "%0"

# define PKT_V_FMT_1 PKT_V_FMT "1x"
# define PKT_V_FMT_2 PKT_V_FMT "2x"
# define PKT_V_FMT_4 PKT_V_FMT "4x"
# define PKT_V_FMT_6 PKT_V_FMT "6x"
# define PKT_V_FMT_8 PKT_V_FMT "8x"

# define PKT_V_3 PKT_V_PREFIX BLU PKT_V_FMT_1 RST
# define PKT_V_4 PKT_V_PREFIX CYA PKT_V_FMT_1 RST
# define PKT_V_8 PKT_V_PREFIX GRE PKT_V_FMT_2 RST
# define PKT_V_13 PKT_V_PREFIX YEL PKT_V_FMT_4 RST
# define PKT_V_16 PKT_V_PREFIX ORA PKT_V_FMT_4 RST
# define PKT_V_24 PKT_V_PREFIX RED PKT_V_FMT_6 RST
# define PKT_V_32 PKT_V_PREFIX PUR PKT_V_FMT_8 RST

# define PKT_3 " " PKT_V_3 " "
# define PKT_4 "  " PKT_V_4 "  "
# define PKT_8 "     " PKT_V_8 "      "
# define PKT_13 "         " PKT_V_13 "          "
# define PKT_16 "            " PKT_V_16 "             "
# define PKT_24 "                   " PKT_V_24 "                    "
# define PKT_32 "                          " PKT_V_32 \
"                           "

# define FMT_BIN_BAR \
" 0                   1                   2                   3\n" \
" 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1\n"

# if FT_PING_USE_IP_OPTS == 1
#  define FMT_IPHDR \
"Internet Header Format\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_4 "|" PKT_4 "|" PKT_8 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_16 "|" PKT_3 "|" PKT_13 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_8 "|" PKT_8 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_32 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_32 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_24 "|" PKT_8 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
# else
#  define FMT_IPHDR \
"Internet Header Format\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_4 "|" PKT_4 "|" PKT_8 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_16 "|" PKT_3 "|" PKT_13 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_8 "|" PKT_8 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_32 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_32 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
# endif // FT_PING_USE_IP_OPTS == 1

# define FMT_ICMPHDR_ECHO \
"ICMP: Echo or Echo Reply Message\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_8 "|" PKT_8 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" \
"|" PKT_16 "|" PKT_16 "|\n" \
"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"

#endif // PACKET_H
