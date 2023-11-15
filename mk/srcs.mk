# SRCS
SRC_C_MANDATORY := help.c \
				   main.c \
				   packet_icmp.c \
				   packet_ip.c \
				   packet_print.c \
				   parsing.c \
				   process.c \
				   usage.c \
				   version.c

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
