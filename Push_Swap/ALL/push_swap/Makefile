# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:45:58 by jodos-sa          #+#    #+#              #
#    Updated: 2023/04/16 12:53:04 by jodos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #

# This is a minimal set of ANSI/VT100 color codes
_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m

# Colors
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m

# Inverted, i.e. colored backgrounds
_IGREY		=	\e[40m
_IRED		=	\e[41m
_IGREEN		=	\e[42m
_IYELLOW	=	\e[43m
_IBLUE		=	\e[44m
_IPURPLE	=	\e[45m
_ICYAN		=	\e[46m
_IWHITE		=	\e[47m


# **************************************************************************** #


CC			= cc
CFLAGS		= -g -Wall -Werror -Wextra


RM			= rm -rf


NAME		= push_swap


INCLUDE		= ./inc/
SRC_PATH	= ./src/
OBJ_PATH	= ./obj/



SOURCES		=	align_stacks.c \
				bruteforce_operations.c \
				bruteforce.c \
				cleaner.c \
				copy_stack.c \
				debug.c	\
				instrunc.c \
				movements.c \
				pick_inst.c \
				print.c \
				resolution.c \
				push_swap.c \
				stacks.c \
				start_stacks.c \
				states.c \
				utils.c \


SRC	= $(SOURCES)
OBJ	= $(SRC:%.c=$(OBJ_PATH)%.o)


all: $(NAME)

$(NAME): $(OBJ)
	@printf "\033[2K\r$(_GREEN) All files compiled into '$(OBJ_PATH)'. $(_END)\n"
	@$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ) -o $(NAME)
	@printf "\033[2K\r$(_GREEN) Executable '$(NAME)' created. $(_END)\n"

$(OBJ):		| $(OBJ_PATH)


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END) "
				@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_PATH):
				@mkdir $(OBJ_PATH)

clean:
	@$(RM) $(OBJ_PATH) $(OBJ_PATH_BONUS)
	@printf "\033[2K\r$(_RED) '"$(OBJ_PATH)"' has been deleted. $(_END)\n"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@printf "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

re: fclean all