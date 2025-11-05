NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC = srcs/main.c \
	srcs/file_utils.c \
	srcs/parse.c \
	srcs/validate.c \
	srcs/solve.c \
	srcs/solve2.c \
	srcs/display.c \
	srcs/error.c \
	srcs/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
