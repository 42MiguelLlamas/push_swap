NAME = push_swap
SRCS = main.c arg_check.c free.c algo_aux.c algorithm.c control.c  swap_a.c swap_b.c ss.c push_a.c push_b.c rotate_a.c rotate_b.c rr.c reverse_rotate_a.c reverse_rotate_b.c rrr.c 
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -fsanitize=address


.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c pushswap.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  -o $(NAME) $(OBJS)