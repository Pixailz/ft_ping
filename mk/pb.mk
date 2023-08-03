# CONFIG
PB_BEGIN_TS			:= 0
PB_LOAD_TTS			:= 0.2
PB_INDEX			:= 0
SCREEN_COL			= $$(TERM=xterm-256color tput cols)
SCREEN_ROW			= $$(TERM=xterm-256color tput lines)

# UNICODE CHAR
DOWN_8				:="⣿"
DOWN_7				:="⣷"
DOWN_6				:="⣶"
DOWN_5				:="⣦"
DOWN_4				:="⣤"
DOWN_3				:="⣄"
DOWN_2				:="⣀"
DOWN_1				:="⡀"
DOWN_0				:="⠀"

# FUNCTION
PB_INIT				= $(eval PB_BEGIN_TS:=$(GET_TS)) $(eval PB_INDEX:=0)
ELAPSED_GOTO_COL	= $(call GOTO_COL,$(shell echo $$(($(SCREEN_COL) - $(1)))))

PB_PRINT_ELAPSED	= \
$(eval PB_ELAPSED:=$(call GET_ELAPSED,$(PB_BEGIN_TS)))							\
$(eval PB_ELAPSED_LEN:=$(shell printf "$(PB_ELAPSED)" | wc -c))					\
$(eval export PB_ELAPSED_LAST_POS:=$(shell echo $$(($(SCREEN_COL) - (13 + $(PB_ELAPSED_LEN))))))	\
$(call GOTO_COL,$(PB_ELAPSED_LAST_POS))											\
printf "(elapsed: $(G)$(PB_ELAPSED)$(RST) ms)"									; \
if [ "$(CREATED_DIR)" == true ]; then											\
	printf "\n"; $(eval CREATED_DIR:=false)										\
fi																				; \


PB_PRINT_HEADER		= \
printf "[$(1)$($(call PB_GET_CHAR))$(RST)] "									; \
$(call PB_PRINT_INDEX)															\
$(call PB_PRINT_PER)

PB_GET_CHAR			= DOWN_$(shell echo $$((($(PB_INDEX) * 8) / $(OBJ_C_NB))))

PB_PRINT_INDEX		= \
printf "($(G)%$(OBJ_C_NB_LEN)d$(RST)/" $(PB_INDEX)								; \
printf "$(R)$(OBJ_C_NB)$(RST))";

PB_PRINT_PER		= printf " %3d%% " "$$((($(PB_INDEX) * 100) / $(OBJ_C_NB)))";


PB_PRINT			= \
if [ $(PB_INDEX) -eq 0 ]; then													\
	$(call P_INF,Creating $(R)objs$(RST))										\
	printf "\n\n"																; \
fi																				; \
printf "%b" "$(CUDL)"															; \
$(call MKDIR,$(@D))																\
$(eval PB_INDEX:=$(shell echo $$(($(PB_INDEX) + 1))))							\
$(call PB_PRINT_HEADER,$(R))													\
printf "Creating $(@)"															; \
$(call PB_PRINT_ELAPSED)														\
if [ $(PB_INDEX) -eq $(OBJ_C_NB) ]; then										\
	$(call PB_DONE)																\
	printf ""																	; \
fi

PB_DONE				= \
printf "%b" "$(CU)"																; \
$(call P_ANSI,$(shell echo $$(($(PB_ELAPSED_LAST_POS) - 1)))G)					\
$(call P_ANSI,1K)																\
$(call P_ANSI,0G)																\
$(call PB_PRINT_HEADER,$(G))													\
printf "Successfully created $(G)objs$(RST)\n";

PB_TARGET_DONE		= \
$(eval PB_INDEX:=$(shell echo $$(($(PB_INDEX) + 1))))							\
$(eval OBJ_C_NB:=$(shell echo $$(($(OBJ_C_NB) + 1))))							\
printf "%b" "$(CUDL)"																; \
$(call PB_PRINT_HEADER,$(G))													\
printf "Successfully created $(G)$(TARGET)$(RST)"								; \
$(call PB_PRINT_ELAPSED)
