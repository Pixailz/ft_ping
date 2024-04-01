# LIB

INC_TMP				:= $(INC_DIR)
LIBFT				:= $(LIB_DIR)/ft_libft/libft.a
MINI_LIBX			:= $(LIB_DIR)/minilibx-linux/libmlx_Linux.a

ifeq ($(USE_LIBFT),1)
INC_TMP				+= $(LIB_DIR)/ft_libft/inc
LIBS				+= $(LIBFT)
endif
ifeq ($(USE_MINI_LIBX),1)
INC_TMP				+= $(LIB_DIR)/minilibx-linux
LIBS				+= $(MINI_LIBX)
LDFLAGS				+= -Llib/minilibx-linux -L/usr/lib -lXext -lX11 -lm -lbsd -lz
endif

INC_DIR				:= $(addprefix -I,$(INC_TMP))
CFLAGS				+= $(LDFLAGS) $(INC_DIR)
