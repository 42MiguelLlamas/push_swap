#include "pushswap.h"

void    push_b(t_element **top_a, t_element **top_b)
{
    if (*top_a != NULL)
    {
        *top_b = t_insert(*top_b, ((*top_a)->num));
        t_free(top_a);
    }
    ft_printf("%s\n","pb");
}