# SRCS
SRC_C_MANDATORY := mandatory/main.c \
				   mandatory/utils/utils.1.c \
				   mandatory/utils/utils.2.c \
				   mandatory/utils/utils.3.c \
				   mandatory/utils/utils.4.c \
				   mandatory/utils/utils.5.c

SRC_C_BONUS := bonus/main.c \
			   bonus/utils/utils.1.c \
			   bonus/utils/utils.1/utils.1.c \
			   bonus/utils/utils.1/utils.2.c \
			   bonus/utils/utils.1/utils.3.c \
			   bonus/utils/utils.1/utils.4.c \
			   bonus/utils/utils.2.c \
			   bonus/utils/utils.3.c \
			   bonus/utils/utils.4.c

ifeq ($(BONUS),1)
TARGET				:= $(TARGET_BONUS)
SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C_BONUS))
else
SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C_MANDATORY))
endif

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
