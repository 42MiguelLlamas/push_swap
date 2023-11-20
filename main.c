#include "pushswap.h"

int main(int argc, char **argv)
{
    register int    i;
    t_element       *top_a_stack;
    t_element       *top_b_stack;
    //t_element       *temp;

	if (argc < 2)
		return (1);
    i = 0;
    while (argv[++i])
        ft_check(i, argv);
    top_a_stack = NULL;
    while (--argc)
        top_a_stack = t_insert(top_a_stack, ft_atoi(argv[argc]));
    top_b_stack = NULL;
    ft_control(&top_a_stack, &top_b_stack);
    /*
    temp = top_a_stack;
    ft_printf("%s\n", "Stack A:");
    while (temp)
    {
        ft_printf("%d\n", temp->num);
        temp = temp->next;
    }
    temp = top_b_stack;
    ft_printf("%s\n", "Stack B:");
    while (temp)
    {
        ft_printf("%d\n", temp->num);
        temp = temp->next;
    }*/
    final_free(top_a_stack, top_b_stack);
    return (0);
}

