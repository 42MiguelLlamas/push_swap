#include "pushswap.h"

void    push_b(t_element **top_a, t_element **top_b)
{
    t_element *temp;

    if (*top_a != NULL)
    {
        temp = *top_a;
        *top_a = (*top_a)->next;
        temp->next = *top_b;
        *top_b = temp;
    }
    write(1, "pb\n", 3);
}