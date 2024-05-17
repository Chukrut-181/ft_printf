NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c print_utils.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar crs $(NAME) $(OBJS)
	@echo "libftprintf.a compilation OK"

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "All .o files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "libftprintf.a removed"

re: fclean all

.PHONY: all clean fclean re