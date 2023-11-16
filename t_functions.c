#include "pushswap.h"

t_element   *t_insert(t_element *top, int number)
{
    t_element   *temp;
    temp = malloc(sizeof(t_element));
    if (!temp)
    {
        while (top)
            t_free(&top);
        return (NULL);
    }
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

void    final_free(t_element *top_a, t_element *top_b)
{
    while (top_a)
        t_free(&top_a);
    while (top_a)
        t_free(&top_b);
}