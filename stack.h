#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "ft_printf.h"

typedef struct s_element{
  int  *key;
  struct s_element *next;
}t_element;
t_element	*ft_lstnew(void *content);
int main(int argc, char **argv);
int	ft_atoi(const char *str);
int	ft_isalpha(int a);
void ft_check(const char *str);
#endif