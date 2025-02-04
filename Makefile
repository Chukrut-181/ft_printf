# Define the name of the library to be created.
NAME = libftprintf.a

# Compiler to be used for building the project.
CC = cc

# Compiler flags:
# -Wall: Enables all warnings about questionable code.
# -Wextra: Enables additional warnings that are not covered by -Wall.
# -Werror: Treats all warnings as errors, stopping compilation if any warnings occur.
CFLAGS = -Wall -Wextra -Werror

# List of source files for the project.
SRCS = ft_printf.c ft_printf_utils.c\

# Create a list of object files by replacing each .c extension in SRCS with .o.
OBJS = $(SRCS:.c=.o)

# Default target that will be run if no target is specified.
all: $(NAME)

# Rule to create the static library by archiving the object files.
# `ar crs` creates the library:
# - c: Create the archive.
# - r: Replace older object files with new ones.
# - s: Write an index to the archive for faster access.
# Prints a message when the library is created.
$(NAME) : $(OBJS)
	ar crs $(NAME) $(OBJS)
	@echo "libftprintf.a compilation OK"

# Rule to compile each .c file into a .o file.
# $< represents the first dependency (source file), and $@ is the target (object file).
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Removes all object files created during compilation.
clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "All .o files removed"

# Removes the library file along with object files.
fclean: clean
	@rm -f $(NAME)
	@echo "libftprintf.a removed"

# Rebuilds the entire project from scratch by running fclean, then all.
re: fclean all

# .PHONY tells Make that these are not actual files, but rather command names.
.PHONY: all clean fclean re