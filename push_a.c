#include "pushswap.h"

void    push_a(t_element **top_a, t_element **top_b)
{
    if (*top_b != NULL)
    {
        *top_a = t_insert(*top_a, ((*top_b)->num));
        t_free(top_b);
    }
}