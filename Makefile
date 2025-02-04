NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c\

OBJ_DIR = objects
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)
	@echo "$(GREEN)libftprintf.a compilation OK$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Objects directory removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)libftprintf.a removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
