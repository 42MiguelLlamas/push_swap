#include "pushswap.h"

void    push_b(t_element **top_a, t_element **top_b)
{
    t_element *temp;

    if (*top_a != NULL)
    {
<<<<<<< HEAD
        temp = *top_a;
        *top_a = (*top_a)->next;
        temp->next = *top_b;
        *top_b = temp;
=======
        *top_b = *top_a;
        *top_a = (*top_a)->next;
>>>>>>> ef254f3d927186bfe573136a96ec9052672a2972
    }
    ft_printf("%s\n","pb");
}