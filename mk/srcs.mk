# SRCS
SRC_C_MANDATORY := cmd/help.c \
				   cmd/usage.c \
				   cmd/version.c \
				   data/conf.c \
				   data/free.c \
				   data/init.c \
				   data/parsing.c \
				   main.c \
				   packet/checksum.c \
				   packet/icmp.c \
				   packet/ip.c \
				   packet/print.c \
				   process.c \
				   recv_pong.c \
				   run.c \
				   send_ping.c \
				   socket.c \
				   stats/print.c \
				   stats/rtt.c

SRC_C_BONUS := main.c

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
