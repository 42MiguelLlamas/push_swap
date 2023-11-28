#include "pushswap.h"

void    swap_a(t_element **top)
{
    t_element *temp;

    if (*top != NULL && (*top)->next != NULL)
    {
        temp = (*top)->next;
        (*top)->next = temp->next;
        temp->next = *top;
        *top = temp;
    }
    write(1, "sa\n", 3);
}