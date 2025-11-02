# **************************************************************************** #
#                                   RUSH-02                                    #
# **************************************************************************** #

NAME        = rush-02
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = includes
SRCS_DIR    = srcs
SRCS        = $(addprefix $(SRCS_DIR)/, \
				main.c dict.c dict2.c parse.c convert.c utils.c utils2.c error.c)
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
