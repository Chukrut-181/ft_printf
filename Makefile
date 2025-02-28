NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c\

BONUS_SRCS = ft_printf_bonus.c ft_printf_utils_bonus.c \
ft_printf_libft_bonus.c ft_printf_padding_bonus.c ft_printf_parse_utils_bonus.c \

OBJ_DIR = objects
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

BONUS_OBJ_DIR = bonus_objects
BONUS_OBJS = $(BONUS_SRCS:%.c=$(BONUS_OBJ_DIR)/%.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)
	@echo "$(GREEN)-> Ft_printf: libftprintf.a compilation OK$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	@mkdir -p $(BONUS_OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BONUS_OBJ_DIR)/%.o: %.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(BONUS_OBJS)
	@ar crs $(NAME) $(BONUS_OBJS)
	@echo "$(GREEN)-> Ft_printf: libftprintf.a (with bonus) compilation OK$(RESET)"

clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@echo "$(YELLOW)-> Ft_printf: objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)-> Ft_printf: libftprintf.a removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
