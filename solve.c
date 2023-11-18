#include "pushswap.h"

int ft_min(t_element *top)
{

}
int *count_solve(t_element **top_a,t_element **top_b)
{
    int min;
    int max;
    int *solution;

    min = ft_min(*top_a);
    max = ft_max(*top_a);
    auxiliar = malloc((max - min)*sizeof(int))
    if (!solution)
    {
        final_free(top_a_stack, top_b_stack);
        exit(1);
    }
    while (top_a->next)
    {
        solution = ft_check((top_a)->num, max - min);
        *top_a = (*top_a)->next;
    }
    return (solution);
}