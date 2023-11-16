#include "pushswap.h"

void    ft_solve(t_element *top_a_stack, t_element *top_b_stack)
{
    top_a_stack = top_a_stack;
    top_b_stack = top_b_stack;
    return ;
}
int main(int argc, char **argv)
{
    register int    i;
    t_element       *top_a_stack;
    t_element       *top_b_stack;

	if (argc < 2)
		return (1);
    i = 0;
    while (argv[++i])
        ft_check(i, argv);
    top_a_stack = NULL;
    while (--argc)
        top_a_stack = t_insert(top_a_stack, ft_atoi(argv[argc]));
    top_b_stack = NULL;
    top_b_stack = t_insert(top_b_stack, 42);
    ft_solve(top_a_stack, top_b_stack);
    //swap_a(&top_a_stack);
    ft_printf("top b: %d\n ", top_b_stack->num);
    push_a(&top_a_stack, &top_b_stack);
    reverse_rotate_a(&top_a_stack);
    while (top_a_stack)
    {
        ft_printf("voy a liberar: %d\n ", top_a_stack->num);
        t_free(&top_a_stack);
    }
    return (0);
}

