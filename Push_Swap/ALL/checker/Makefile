# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 16:50:34 by jodos-sa          #+#    #+#              #
#    Updated: 2023/04/17 14:56:11 by jodos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## PIMPED MAKEFILE ##

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


CC			=	gcc

CC_FLAGS	=	-Wall -Wextra -Werror



RM			=	rm -rf




INCLUDES =	./inc/

SRC_PATH	=	./bonus/

OBJ_PATH	=	./obj/




SOURCES			=	begin_stacks.c \
				checker.c \
				cleaner.c \
				debug.c \
				get_instructions.c \
				instrunc.c \
				pick_inst.c \
				print.c \
				utils.c \
				utils2.c

SRC		=	$(SOURCES)

# COMPILED_SOURCES #

OBJS 		=	$(SRC:%.c=$(OBJ_PATH)%.o)

NAME 		=	checker


# **************************************************************************** #

## RULES ##

all:			$(NAME)

# VARIABLES RULES #

$(NAME):		$(OBJS)
				@printf "\033[2K\r$(_GREEN) All files compiled into '$(OBJ_PATH)'. $(_END)\n"
				@$(CC) $(CC_FLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME)
				@printf "\033[2K\r$(_GREEN) Executable '$(NAME)' created. $(_END)\n"

# COMPILED_SOURCES RULES #

$(OBJS):		| $(OBJ_PATH)


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END) "
				@$(CC) $(CC_FLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJ_PATH):
				@mkdir $(OBJ_PATH)


# OBLIGATORY PART #

clean:
				@$(RM) $(OBJ_PATH)
				@printf "\033[2K\r$(_RED) '"$(OBJ_PATH)"' has been deleted. $(_END)\n"

fclean:			clean
				@$(RM) $(NAME)
				@printf "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

re:				fclean all

# NORME #

norm:
				@$(NORMINETTE) $(SRC_PATH)
				@$(NORMINETTE) $(INCLUDES)

# PHONY #

.PHONY:			all debug clean fclean re norm
