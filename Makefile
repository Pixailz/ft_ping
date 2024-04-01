# include
include mk/config.mk			# base config
include mk/utils.mk				# utils function / var
include mk/lib.mk				# load lib if needed
include mk/srcs.mk				# srcs.mk
include mk/pb.mk				# ui thing, progress bar etc

$(call PB_INIT)

# rule
## config
.SILENT:

.PHONY: setup

.DEFAULT: all

all:			setup $(TARGET) $(LIBS)

### TARGETS
$(TARGET):		$(LIBS) $(OBJ_C)
> $(call P_INF,Creating $(R)$(TARGET)$(RST))
> printf "\n\n"
> $(call PB_PRINT_ELAPSED)
> $(CC) $(CFLAGS) -o $@ $(OBJ_C) $(LIBS)
> $(call PB_TARGET_DONE)

## objs
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
# $(<)		: dependencies
# $(@)		: full target
# $(@D)		: dir target
$(OBJ_C):		$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
> $(call PB_PRINT,$(@))
> $(CC) $(CFLAGS) -o $@ -c $<

### LIBS
$(LIBFT):
ifeq ($(USE_LIBFT),1)
> PROG_NAME=$(TARGET) DEBUG=$(DEBUG) DEBUG_FD=$(DEBUG_FD) AUTHOR=$(AUTHOR) \
	VERSION=$(VERSION) make -C lib/ft_libft all
endif

$(MINI_LIBX):
ifeq ($(USE_MINI_LIBX),1)
> make -C lib/minilibx-linux all
endif

setup:	$(BIN_DIR) print_logo print_debug helper

$(BIN_DIR):
> $(call MKDIR,$(BIN_DIR))

print_debug:
ifeq ($(shell [ $(DEBUG) -ge 1 ] && printf 1 || printf 0),1)
> $(call P_INF,RUNTIME INFOS)
> printf "\t%s"
> $(call P_WAR,DEBUG: $(DEBUG))
> printf "\t%s"
> $(call P_WAR,CFLAGS:)
> printf "\t\t%s\n" $(CFLAGS)
> printf "\t%s"
> $(call P_WAR,.SHELLFLAGS:)
> printf "\t\t%s\n"  $(.SHELLFLAGS)
> printf "\t%s"
> $(call P_WAR,OBJ_C:)
> printf "\t\t%s\n"  $(OBJ_C)
> printf "\t%s"
> $(call P_WAR,SRC_C:)
> printf "\t\t%s\n"  $(SRC_C)
endif

print_logo:
ifeq ($(LOGO_PRINTED),)
> printf "%b\n" "$(ASCII_COLOR)$$ASCII_BANNER$(RST)"
> $(eval export LOGO_PRINTED=1)
endif

### HELPER

helper:				export_vars
> ./rsc/helper/helper -S ft_ping

export_vars:
export MK_DIR
export SRC_DIR

### RUN
run:					setup $(TARGET)
> ./$(TARGET) --usage

### CLEAN
clean:
> $(call P_FAI,Removing obj)
> rm -rf $(OBJ_DIR)

clean_all:				clean
ifeq ($(USE_LIBFT),1)
> make -C lib/ft_libft clean
endif
ifeq ($(USE_MINI_LIBX),1)
> make -C lib/minilibx-linux clean
endif

fclean:							clean
ifeq ($(BONUS),1)
> $(call P_FAI,Removing $(TARGET))
> rm -rf $(TARGET)
else
> $(call P_FAI,Removing $(TARGET_BONUS))
> rm -rf $(TARGET_BONUS)
endif

fclean_all:				fclean
ifeq ($(USE_LIBFT),1)
> make -C lib/ft_libft fclean
endif
ifeq ($(USE_MINI_LIBX),1)
> make -C lib/minilibx-linux clean
endif

### RE
re:						setup fclean $(TARGET)

re_all:					re_lib re

re_lib:
ifeq ($(USE_LIBFT),1)
> make -C ./lib/ft_libft re
endif
ifeq ($(USE_MINI_LIBX),1)
> make -C ./lib/minilibx-linux re
endif
