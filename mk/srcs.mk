# SRCS
SRC_C := cmd/help.c \
		 cmd/usage.c \
		 data/conf.c \
		 data/exit.c \
		 data/free.c \
		 data/init.c \
		 error.c \
		 interrupt.c \
		 main.c \
		 packet/get_packet_size.c \
		 packet/icmp.c \
		 packet/ip.c \
		 packet/print.c \
		 parsing/parse.c \
		 parsing/post_parse.c \
		 parsing/post_parse_conf_1.c \
		 parsing/post_parse_conf_2.c \
		 parsing/post_parse_pattern.c \
		 process.c \
		 recv_pong.c \
		 run.c \
		 send_ping.c \
		 stats/print.c \
		 stats/rtt.c

SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
