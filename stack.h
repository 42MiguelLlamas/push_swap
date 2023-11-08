#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typdef struct s_element{
  int  *key;
  struct s_element *next;
}t_element