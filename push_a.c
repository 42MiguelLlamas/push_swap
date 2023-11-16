#include "pushswap.h"

void    push_a(t_element **top_a, t_element **top_b)
{
    t_element *temp;

    if (*top_b != NULL)
    {
        temp = *top_b;
        *top_b = (*top_b)->next;
        temp->next = *top_a;
        *top_a = temp;
    }
    ft_printf("%s\n","pa");
}