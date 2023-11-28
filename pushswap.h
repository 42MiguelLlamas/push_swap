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


void    t_free(t_element **top);
void    final_free(t_element *top_a, t_element *top_b);

int       main(int argc, char **argv);
void      printtt(t_element *top_a_stack, t_element *top_b_stack);

int     t_check_a(t_element *top);
int     t_length(t_element *top);
int     ft_min(t_element *top);
int     find_min(t_element *top);
t_element *ft_last(t_element *top);
void    ft_solvethree_a(t_element **top);
void    ft_roulette(t_element **top_a, t_element **top_b);
void    ft_solve(t_element **top_a_stack, t_element **top_b_stack);

int     ft_check_t(t_element *top);
void    ft_solvethree(t_element **top);
int     ft_length(t_element *top);
int     ft_mini(t_element *top);
int     ft_rot_min(t_element *top, int len);
int     rotations_dest(t_element *a, t_element *top_b, int len);
int    *ft_costs(t_element **top_a, t_element **top_b, int len);
int     ft_sense(int index, int min_index, int len);
int     ft_direction(t_element *a, t_element *top, int len);
void    ft_do_a(t_element **top_a, t_element **top_b, int index, int len);
void ft_do_b(t_element **top_a, t_element **top_b, int index, int lena, int lenb);
int     ft_index(int *costs, int len);
void    ft_rotate(t_element **top_a);
void    ft_algorith(t_element **top_a, t_element **top_b);
void    ft_control(t_element **top_a, t_element **top_b);

void    swap_a(t_element **top);
void    swap_b(t_element **top);
void    ss(t_element **top_a, t_element **top_b);
void    push_a(t_element **top_a, t_element **top_b);
void    push_b(t_element **top_a, t_element **top_b);
void    rotate_a(t_element **top);
void    rotate_b(t_element **top);
void    rr(t_element **top_a, t_element **top_b);
void    reverse_rotate_a(t_element **top);
void    reverse_rotate_b(t_element **top);
void    rrr(t_element **top_a, t_element **top_b);


int	      ft_atoi(char *str);
int	      ft_strncmp(const char *s1, const char *s2, size_t n);
void      ft_check(int index, char **argv);
void      ft_exit(void);
size_t	  ft_strlen(const char *s);
t_element *t_insert(t_element *top, int number);
#endif