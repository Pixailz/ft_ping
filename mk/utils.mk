# ALIAS
## check if $(1): is a dir and if $(1) not present, then make it
MKDIR			= \
[ -f $(1) ] && rm -f $(1)														; \
if [ ! -d $(1) ]; then															\
	mkdir -p $(1)																; \
	$(call P_INF,Dir $(1) not found creating it)								\
	$(eval CREATED_DIR:=true)													\
	printf "\n"																	; \
fi																				; \

## Timestamps function
GET_TS				= $(shell date +"%s%3N")
GET_ELAPSED			= $(shell echo $$(($(call GET_TS) - $(1))))

## Bash test function
IS_GE				= [ $(1) -ge $(2) ] && printf 1 || printf 0 ;
IS_Z_OR_E			= [ -z $(1) -o $(1) -eq 0 ] && printf 1 || printf 0 ;

## print function
P_ANSI				= printf "%b" "$(ESC)$(1)";
P_INF				= printf "[%b] %b" "$(I)" "$(1)"; $(call PB_PRINT_ELAPSED)
P_WAR				= printf "[%b] %b" "$(W)" "$(1)"; $(call PB_PRINT_ELAPSED)
P_PAS				= printf "[%b] %b" "$(P)" "$(1)"; $(call PB_PRINT_ELAPSED)
P_FAI				= printf "[%b] %b" "$(F)" "$(1)"; $(call PB_PRINT_ELAPSED)
## ansi mov cursor
GOTO_COL			= $(call P_ANSI,$(1)G)

# ANSI
ESC					:= \x1b[
## COLOR
RST					:= $(ESC)0m
R					:= $(ESC)31m
G					:= $(ESC)32m
Y					:= $(ESC)33m
B					:= $(ESC)34m
M					:= $(ESC)35m
C					:= $(ESC)36m
O					:= $(ESC)38;5;214m

### COMPOSITE
I					:= $(B)i$(RST)
W					:= $(O)⚠$(RST)
P					:= $(G)✓$(RST)
F					:= $(R)✗$(RST)
ASCII_COLOR			:= $(G)

## CURSOR
CU					:= $(ESC)1F
DL					:= $(ESC)2K
CUDL				:= $(CU)$(DL)

# ASCII BANNER
define ASCII_BANNER
███████╗████████╗     ██████╗ ██╗███╗   ██╗ ██████╗
██╔════╝╚══██╔══╝     ██╔══██╗██║████╗  ██║██╔════╝
█████╗     ██║        ██████╔╝██║██╔██╗ ██║██║  ███╗
██╔══╝     ██║        ██╔═══╝ ██║██║╚██╗██║██║   ██║
██║        ██║███████╗██║     ██║██║ ╚████║╚██████╔╝
╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝╚═╝  ╚═══╝ ╚═════╝
endef
export ASCII_BANNER

