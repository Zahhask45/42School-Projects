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

NAME	= libftprintf.a

SRC_FILES	= ft_printf.c prints.c utils.c format.c string_utils.c \
				prepend.c flags.c convert.c parser.c
SRC 		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP			= $(OBJ:$(OBJ_DIR)/%.o=$(OBJ_DIR)/%.d)

TESTER 		= tester
TESTER_SRC	= src/.main.c

#################### RULES ##########################

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(_GONE)$(_BOLD)$(_YELLOW)⚙️  Compiling $< ⚙️ $(_END)"
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@


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

clean:
	${RM} ${OBJ_DIR}
	@printf "$(_GONE)$(_BOLD)$(_RED)🗑️  Objects removed$(_END) 🗑️ \n"

fclean: clean
	${RM} ${NAME} ${TESTER}
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

.PHONY: all clean fclean re test run

.SILENT:
