# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 14:06:39 by jodos-sa          #+#    #+#              #
#    Updated: 2023/04/16 14:16:27 by jodos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END		=	\e[0m
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


SRC			= ./ALL

DIR			= ./

RM			= rm -rf



CHECKER		= checker
PUSH_SWAP	= push_swap


all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER):
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(CHECKER) $(_END)\n"
				@$(MAKE) -C $(SRC)/$(CHECKER) MAKEFLAGS=
				@cp -rf $(SRC)/$(CHECKER)/$(CHECKER) $(DIR)/$(CHECKER)

$(PUSH_SWAP):	
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(PUSH_SWAP) $(_END)\n"
				@$(MAKE) -C $(SRC)/$(PUSH_SWAP)/ MAKEFLAGS=
				@cp -rf $(SRC)/$(PUSH_SWAP)/$(PUSH_SWAP) ./$(PUSH_SWAP)

clean:
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(CHECKER) $(_END)\n"
				@make clean -C $(SRC)/$(CHECKER)
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(PUSH_SWAP) $(_END)\n"
				@make clean -C $(SRC)/$(PUSH_SWAP)

fclean:			
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(CHECKER) $(_END)\n"
				@make fclean -C $(SRC)/$(CHECKER)
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(PUSH_SWAP) $(_END)\n"
				@make fclean -C $(SRC)/$(PUSH_SWAP)
				@$(RM) $(CHECKER)
				@$(RM) $(PUSH_SWAP)

re:				fclean all
