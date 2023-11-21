#include "pushswap.h"

void    reverse_rotate_a(t_element **top)
{
    t_element *temp;

    if (*top == NULL || (*top)->next == NULL)
        return;
    temp = *top;
    while (temp->next->next)
        temp = temp->next;
    temp->next->next = *top;
    *top = temp->next;
    temp->next = NULL;
    ft_printf("%s\n","rra");
}