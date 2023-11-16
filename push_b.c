#include "pushswap.h"

void    push_b(t_element **top_a, t_element **top_b)
{
    if (*top_a != NULL)
    {
        *top_b = *top_a;
        *top_a = (*top_a)->next;
    }
    ft_printf("%s\n","pb");
}