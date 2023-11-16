NAME = push_swap
SRCS = main.c aux_ft.c t_functions.c swap_a.c push_a.c rotate_a.c reverse_rotate_a.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
LIB_DIR = ft_printf
LIB_NAME = libftprintf.a


.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c pushswap.h
	cc $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

$(LIB_DIR)/$(LIB_NAME): $(LIB_DIR)/Makefile
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIB_DIR)/$(LIB_NAME)
	$(CC) $(CFLAGS) -I$(LIB_DIR) -o $(NAME) $(OBJS) $(LIB_DIR)/$(LIB_NAME) -L$(LIB_DIR) -lftprintf