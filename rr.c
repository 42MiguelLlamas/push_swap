#include "pushswap.h"

void    rr(t_element **top_a, t_element **top_b)
{
    t_element *temp;

    temp = *top_a;
    while (temp->next)
        temp = temp->next;
    temp->next = *top_a;
    *top_a = (*top_a)->next;
    temp->next->next = NULL;
    temp = *top_b;
    while (temp->next)
        temp = temp->next;
    temp->next = *top_b;
    *top_b = (*top_b)->next;
    temp->next->next = NULL;
    ft_printf("%s\n","rrr");
}
