#include "pushswap.h"

void    push_a(t_element **top_a, t_element **top_b)
{
    if (*top_b != NULL)
    {
        *top_a = *top_b;
        *top_b = (*top_b)->next;
    }
    ft_printf("%s\n","pa");
}