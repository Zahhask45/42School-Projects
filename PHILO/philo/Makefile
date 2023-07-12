# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 13:48:23 by jodos-sa          #+#    #+#              #
#    Updated: 2023/06/06 14:21:28 by jodos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m


_GREY		=	\e[1;30m
_RED		=	\e[1;31m
_GREEN		=	\e[1;32m
_YELLOW		=	\e[1;33m
_BLUE		=	\e[1;34m
_PURPLE		=	\e[1;35m
_CYAN		=	\e[1;36m
_WHITE		=	\e[1;37m


_GONE		=	\e[2K\r

CC			= cc
CFLAGS		= -g -pthread -Wall -Werror -Wextra #-fsanitize=thread


RM			= rm -rf


NAME		= philo

INCLUDE		=	-I ./inc/\
				-I ./mlx/minilibx-linux/\
				-I ./libft/

SRC_PATH	= ./src/
OBJ_PATH	= ./obj/



SOURCES		=	philo.c \
				start.c \
				survive.c \
				utils.c \
				finish.c \
				lock.c



SRC	= $(addprefix $(SRC_PATH), $(SOURCES))
OBJS			= $(SOURCES:.c=.o)
OBJ		= $(addprefix $(OBJ_PATH), $(OBJS))


all: $(NAME)


$(NAME): $(OBJ)
	@printf "\033[2K\r$(_GREEN) All files compiled into '$(OBJ_PATH)'. $(_END)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE)
	@printf "\033[2K\r$(_GREEN) Executable '$(NAME)' created. $(_END)\n"

$(OBJ):		| $(OBJ_PATH)


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END) "
				@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_PATH):
				@mkdir $(OBJ_PATH)

clean:
	@$(RM) $(OBJ_PATH) $(OBJ_PATH_BONUS)
	@printf "\033[2K\r$(_RED) '"$(OBJ_PATH)"' has been deleted. $(_END)\n"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@printf "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

re: fclean all