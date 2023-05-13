### COMPILATION ###
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

### EXECUTABLE ###
NAME	= pipex
NAMEB	= pipex_bonus
### INCLUDES ###
INCLUDE	= inc
LIBFT_PATH	= libft
SRC_PATH	= src
OBJ_PATH	= obj

### SOURCE FILES ###
SOURCES = main.c other.c paths.c errors.c
SOURCES_BONUS = main_bonus.c other_bonus.c paths_bonus.c errors_bonus.c

### OBJECTS ###
SRC	= $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJ	= $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

SRCB	= $(addprefix $(SRC_PATH)/,$(SOURCES_BONUS))
OBJB	= $(addprefix $(OBJ_PATH)/,$(SOURCES_BONUS:.c=.o))

### COLORS ###
NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

### RULES ###

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)libft..$(NOC)"
	@make -sC $(LIBFT_PATH)
	@$(CC) $(CFLAGS) -L $(LIBFT_PATH) -o $@ $^ -lft
	@echo "$(GREEN)$@$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE)/$(NAME).h
	@mkdir -p obj
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c -o $@ $<
	@echo "$(BLUE)clang $(WHITE)$(notdir $@)$(NOC)"

clean:
	@echo "$(RED)clean$(NOC)"
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ_PATH)

bonus: $(NAMEB)

$(NAMEB): $(OBJB)
	@echo "$(YELLOW)libft..$(NOC)"
	@make -sC $(LIBFT_PATH)
	@$(CC) -g $(CFLAGS) -L $(LIBFT_PATH) -o $@ $^ -lft
	@echo "$(GREEN)$@$(NOC)"

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME) $(NAMEB)

re: fclean all
