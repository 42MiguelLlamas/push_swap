NAME = pushswap
SRCS = main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIB_DIR = ft_printf
LIB_NAME = libftprintf.a


.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c stack.h
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