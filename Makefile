#################### COLOURS ########################

ifneq (,$(findstring xterm,${TERM}))
	_BLACK			:= $(shell tput setaf 8)
	_RED			:= $(shell tput setaf 9)
	_GREEN			:= $(shell tput setaf 10)
	_YELLOW			:= $(shell tput setaf 11)
	_BLUE			:= $(shell tput setaf 12)
	_PURPLE			:= $(shell tput setaf 13)
	_CYAN			:= $(shell tput setaf 14)
	_WHITE			:= $(shell tput setaf 15)
	_END			:= $(shell tput sgr0)
else
	_BLACK			:= ""
	_RED			:= ""
	_GREEN			:= ""
	_YELLOW			:= ""
	_BLUE			:= ""
	_PURPLE			:= ""
	_CYAN			:= ""
	_WHITE			:= ""
	_END			:= ""
endif


_GONE		=	\e[2K\r

#################### COMPILATION ####################
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -MMD -MP

#################### COMMANDS #######################

LIBC	= ar rc
RM		= rm -rf

#################### FILES ##########################

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

SRC_BONUS_DIR = src_bonus
INC_BONUS_DIR = inc_bonus
OBJ_BONUS_DIR = obj_bonus

NAME	= libftprintf.a

SRC_FILES	= ft_printf.c prints.c utils.c format.c string_utils.c \
				prepend.c flags.c convert.c parser.c
SRC 		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP			= $(OBJ:$(OBJ_DIR)/%.o=$(OBJ_DIR)/%.d)

SRC_BONUS_FILES	= ft_printf_bonus.c prints_bonus.c utils_bonus.c format_bonus.c \
					string_utils_bonus.c prepend_bonus.c flags_bonus.c convert_bonus.c \
					parser_bonus.c
SRC_BONUS	= $(addprefix $(SRC_BONUS_DIR)/, $(SRC_BONUS_FILES))
OBJ_BONUS	= $(SRC_BONUS:$(SRC_BONUS_DIR)/%_bonus.c=$(OBJ_BONUS_DIR)/%_bonus.o)

TESTER 		= tester
TESTER_SRC	= src/.main.c

#################### RULES ##########################

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	mkdir -p $(OBJ_BONUS_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(_GONE)$(_BOLD)$(_YELLOW)⚙️  Compiling $< ⚙️ $(_END)"
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_BONUS_DIR)/%_bonus.o: $(SRC_BONUS_DIR)/%_bonus.c | $(OBJ_BONUS_DIR)
	@printf "$(_GONE)$(_BOLD)$(_YELLOW)⚙️  Compiling $< ⚙️ $(_END)"
	$(CC) $(CFLAGS) -I$(INC_BONUS_DIR) -c $< -o $@


${NAME}: ${OBJ}
	@printf "$(_GONE)$(_BOLD)$(_GREEN)⚙️  Compilation completed$(_END) ⚙️ \n"
	${LIBC} $@ $^
	@printf "$(_GONE)$(_BOLD)$(_GREEN)📋 Archive \`$@\` created$(_END)\n"

test: $(TESTER)

$(TESTER): $(NAME)
	@printf "$(_GONE)$(_BOLD)$(_CYAN)⚙️  Compiling tester ⚙️ $(_END)"
	$(CC) -I$(INC_DIR) $(TESTER_SRC) -L. -lftprintf -o $(TESTER)
	@printf "$(_GONE)$(_BOLD)$(_GREEN)✅ Tester compiled successfully ✅$(_END)\n"

run: test
	@printf "$(_GONE)$(_BOLD)$(_PURPLE)🚀 Running Tester 🚀$(_END)\n\n"
	valgrind --leak-check=full ./$(TESTER)

.bonus: ${OBJ_BONUS}
	@printf "$(_GONE)$(_BOLD)$(_GREEN)⚙️  Compilation completed$(_END) ⚙️ \n"
	${LIBC} ${NAME} $^
	@printf "$(_GONE)$(_BOLD)$(_GREEN)📋 Archive \`${NAME}\` created with bonus$(_END)\n"
	@touch .bonus

bonus: .bonus

clean:
	${RM} ${OBJ_DIR} ${OBJ_BONUS_DIR}
	@printf "$(_GONE)$(_BOLD)$(_RED)🗑️  Objects removed$(_END) 🗑️ \n"

fclean: clean
	${RM} ${NAME} ${TESTER} .bonus
	@printf "$(_GONE)$(_BOLD)$(_RED)🗑️  Archive \`$(NAME)\` removed$(_END) 🗑️ \n"
	@printf "$(_GONE)$(_BOLD)$(_RED)🗑️  Tester \`$(TESTER)\` removed$(_END) 🗑️ \n"

re: fclean all

-include $(DEP)

colors: ## show all the colors
	@echo "${_BLACK}BLACK${_END}"
	@echo "${_RED}RED${_END}"
	@echo "${_GREEN}GREEN${_END}"
	@echo "${_YELLOW}YELLOW${_END}"
	@echo "${_BLUE}BLUE${_END}"
	@echo "${_PURPLE}PURPLE${_END}"
	@echo "${_CYAN}CYAN${_END}"
	@echo "${_WHITE}WHITE${_END}"

.PHONY: all clean fclean re test run bonus

.SILENT:
