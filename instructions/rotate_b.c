#include "pushswap.h"

void    rotate_b(t_element **top)
{
    t_element *temp;

    temp = *top;
    while (temp->next)
        temp = temp->next;
    temp->next = *top;
    *top = (*top)->next;
    temp->next->next = NULL;
    write(1, "rb\n", 3);
}