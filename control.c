#include "pushswap.h"

void    ft_control(t_element **top_a, t_element **top_b)
{
    int *costs;
    int index;

    costs = NULL;
    index = 0;
    if (ft_check_t(*top_a) == 1)
        return ;
    if (ft_length(*top_a) == 2)
    {
        swap_a(top_a);
        return ;
    }
    while (ft_length(*top_a) > 3)
        push_b(top_a, top_b);
    ft_solvethree(top_a);
    while (ft_length(*top_b) > 0)
    {
        costs = ft_costs(top_b, top_a, ft_length(*top_b));
        index = ft_index(costs, ft_length(*top_b));
        ft_do_b(top_a, top_b, index, ft_length(*top_a), ft_length(*top_b));
    }
    ft_rotate(top_a);
}

void    ft_solvethree(t_element **top)
{
    int max;

    max = ft_max(*top);
    if (max == (*top)->next->num)
        reverse_rotate_a(top);
    else if (max == (*top)->num)
        rotate_a(top);
    if ((*top)->num >(*top)->next->num)
        swap_a(top);
    return ;
}

void ft_do_b(t_element **top_a, t_element **top_b, int index, int lena, int lenb)
{
    int rot_dst;
    int uod;

    if (index <= lenb / 2)
    {
        while (index-- > 0)
            rotate_b(top_b);
    }
    else
    {
        while (index++ < lenb)
            reverse_rotate_b(top_b);
    }
    rot_dst = rotations_dest (*top_b, *top_a, lena);
    uod = ft_direction(*top_b, *top_a, lena);
    while (uod == 0 && rot_dst-- > 0)
        rotate_a(top_a);
    while (uod == 1 && rot_dst-- > 0)
        reverse_rotate_a(top_a);
    push_a(top_a, top_b);
}

void    ft_rotate(t_element **top_a)
{
    int min;
    int index;
    t_element *temp;

    temp = *top_a;
    index = 0;
    min = ft_mini(*top_a);
    while (temp && temp->num != min)
    {
        temp = temp->next;
        index++;
    }
    if (index <= ft_length(*top_a) / 2)
    {
        while (index-- > 0)
            rotate_a(top_a);
    }
    else
    {
        while (index++ < ft_length(*top_a))
            reverse_rotate_a(top_a);
    }
}