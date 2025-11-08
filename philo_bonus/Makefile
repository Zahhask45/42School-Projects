_END		=	\e[0m
_BOLD		=	\e[1m
_CLEAR		=	\e[2m
_ITALIC		=	\e[3m
_UNDER		=	\e[4m
_BLINK		=	\e[5m
_RAPIDBLINK	=	\e[6m
_REV		=	\e[7m
_HIDE		=	\e[8m
_MID		=	\e[9m
_DUNDER		=	\e[21m

_BLACK		=	\e[1;30m
_RED		=	\e[1;31m
_GREEN		=	\e[1;32m
_YELLOW		=	\e[1;33m
_BLUE		=	\e[1;34m
_PURPLE		=	\e[1;35m
_CYAN		=	\e[1;36m
_GREY		=	\e[1;37m

_BACKBLACK	=	\e[1;40m
_BACKRED	=	\e[1;41m
_BACKGREEN	=	\e[1;42m
_BACKYELLOW	=	\e[1;43m
_BACKBLUE	=	\e[1;44m
_BACKPURPLE	=	\e[1;45m
_BACKCYAN	=	\e[1;46m
_BACKGREY	=	\e[1;47m


_GONE		=	\e[2K\r

CC			=	cc
CFLAGS		=	-g -pthread -Wall -Werror -Wextra -fsanitize=address


RM			=	rm -rf


NAME		=	philo_bonus

INCLUDE		=	-I ./inc/

SRC_PATH	=	./src/
OBJ_PATH	=	./obj/



SOURCES		=	main.c \
				utils.c \
				check.c



SRC		=	$(addprefix $(SRC_PATH), $(SOURCES))
OBJS	=	$(SOURCES:.c=.o)
OBJ		=	$(addprefix $(OBJ_PATH), $(OBJS))


all: $(NAME)


$(NAME): $(OBJ)
	printf "$(_GONE)$(_GREEN) All files compiled into '$(OBJ_PATH)'. $(_END)\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE)
	printf "$(_GONE)$(_GREEN) Executable '$(NAME)' created. $(_END)\n"

$(OBJ):		| $(OBJ_PATH)


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				printf "$(_GONE) $(_YELLOW)Compiling $< $(_END) "
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_PATH):
				mkdir $(OBJ_PATH)

clean:
	$(RM) $(OBJ_PATH) $(OBJ_PATH_BONUS)
	printf "$(_GONE)$(_RED) '"$(OBJ_PATH)"' has been deleted. $(_END)\n"

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	printf "$(_GONE)$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

re: fclean all

print:
		printf "$(_BOLD)$(_ITALIC)$(_UNDER)$(_BLINK)$(_MID)$(_DUNDER)$(_RAPIDBLINK)TEST TEST, OK ALL DONE\n"
		printf "$(_RED)TEST TEST, OK ALL DONE\n"
		printf "$(_GREEN)TEST TEST, OK ALL DONE\n"
		printf "$(_YELLOW)TEST TEST, OK ALL DONE\n"
		printf "$(_BLUE)TEST TEST, OK ALL DONE\n"
		printf "$(_PURPLE)TEST TEST, OK ALL DONE\n"
		printf "$(_CYAN)TEST TEST, OK ALL DONE\n"
		printf "$(_GREY)TEST TEST, OK ALL DONE\n"

portugal:
		printf "$(_BACKRED)                       $(_BACKGREEN)            $(_END)\n"
		printf "$(_BACKRED)                       $(_BACKGREEN)            $(_END)\n"
		printf "$(_BACKRED)                   $(_BACKYELLOW)        $(_BACKGREEN)        $(_END)\n"
		printf "$(_BACKRED)                   $(_BACKYELLOW)        $(_BACKGREEN)        $(_END)\n"
		printf "$(_BACKRED)                       $(_BACKGREEN)            $(_END)\n"
		printf "$(_BACKRED)                       $(_BACKGREEN)            $(_END)\n"

.SILENT: