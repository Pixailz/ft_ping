# SRCS
SRC_C_MANDATORY := cmd/help.c \
				   cmd/usage.c \
				   cmd/version.c \
				   data/conf.c \
				   data/exit.c \
				   data/free.c \
				   data/init.c \
				   error.c \
				   interrupt.c \
				   main.c \
				   packet/checksum.c \
				   packet/icmp.c \
				   packet/ip.c \
				   packet/print.c \
				   parsing/parse.c \
				   parsing/post_parse.c \
				   parsing/post_parse_cmd.c \
				   parsing/post_parse_conf_1.c \
				   process.c \
				   recv_pong.c \
				   run.c \
				   send_ping.c \
				   stats/print.c \
				   stats/rtt.c

SRC_C_BONUS := cmd/help.c \
			   cmd/usage.c \
			   cmd/version.c \
			   data/conf.c \
			   data/exit.c \
			   data/free.c \
			   data/init.c \
			   error.c \
			   interrupt.c \
			   main.c \
			   packet/checksum.c \
			   packet/icmp.c \
			   packet/ip.c \
			   packet/print.c \
			   parsing/parse.c \
			   parsing/post_parse.c \
			   parsing/post_parse_cmd.c \
			   parsing/post_parse_conf_1.c \
			   process.c \
			   recv_pong.c \
			   run.c \
			   send_ping.c \
			   stats/print.c \
			   stats/rtt.c

ifeq ($(BONUS),1)
TARGET				:= $(TARGET_BONUS)
SRC_C				:= $(addprefix $(SRC_DIR)/bonus/,$(SRC_C_BONUS))
else
SRC_C				:= $(addprefix $(SRC_DIR)/mandatory/,$(SRC_C_MANDATORY))
endif

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
