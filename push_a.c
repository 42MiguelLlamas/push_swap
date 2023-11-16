#include "pushswap.h"

void    push_a(t_element **top_a, t_element **top_b)
{
    t_element *temp;

    if (*top_b != NULL)
    {
<<<<<<< HEAD
        temp = *top_b;
        *top_b = (*top_b)->next;
        temp->next = *top_a;
        *top_a = temp;
=======
        *top_a = *top_b;
        *top_b = (*top_b)->next;
>>>>>>> ef254f3d927186bfe573136a96ec9052672a2972
    }
    ft_printf("%s\n","pa");
}