
NAME = pushswap.a
SRCS = main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra


.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)