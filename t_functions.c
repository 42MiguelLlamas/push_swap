#include "pushswap.h"

t_element   *t_insert(t_element *top, int number)
{
    t_element   *temp;
    temp = malloc(sizeof(t_element));
    if (!temp)
        return (NULL);
    temp->num = number;
    temp->next = top;
    top = temp;
    return (top);
}

void    t_free(t_element **top)
{
    t_element   *temp;

    temp = *top;
    *top = (*top)->next;
    free(temp);
}