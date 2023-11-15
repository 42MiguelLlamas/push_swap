#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "ft_printf.h"

typedef struct s_element{
  int num;
  struct s_element *next;
}t_element;
t_element *t_insert(t_element *top, int number);
t_element *t_free(t_element *top);
int       main(int argc, char **argv);
void    ft_solve(t_element *top_a_stack, t_element *top_b_stack);
int	      ft_atoi(char *str);
void      ft_check(int index, char **argv);
void      ft_exit(void);
size_t	  ft_strlen(const char *s);
#endif