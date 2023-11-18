#include "pushswap.h"

int t_check_a(t_element *top)
{

    if (top == NULL || (top)->next == NULL)
        return (1);
    while ((top)->next != NULL && (top)->num < (top)->next->num)
    {
        top = (top)->next;
    }
    if ((top)->next == NULL)
        return (1);
    return (0);
}

int t_check_b(t_element *top)
{

    if (top == NULL || (top)->next == NULL)
        return (1);
    while ((top)->next != NULL && (top)->num > (top)->next->num)
    {
        top = (top)->next;
    }
    if ((top)->next == NULL)
        return (1);
    return (0);
}

int t_length(t_element *top)
{
    int    len;

    len = 0;
    if (top == NULL)
        return (len);
    while (top)
    {
        top = top->next;
        len++;
    }
    return (len);
}

void    ft_solvethree_a(t_element **top)
{
    if ((*top)->num < (*top)->next->num && (*top)->num < (*top)->next->next->num)
    {
        swap_a(top);
        rotate_a(top);
    }
    if ((*top)->num < (*top)->next->num && (*top)->num > (*top)->next->next->num)
        reverse_rotate_a(top);
    if ((*top)->num > (*top)->next->num && (*top)->num < (*top)->next->next->num)
        swap_a(top);
    if ((*top)->num > (*top)->next->num && (*top)->next->num > (*top)->next->next->num)
    {
        swap_a(top);
        reverse_rotate_a(top);
    }
    if ((*top)->num > (*top)->next->num && (*top)->next->num < (*top)->next->next->num)
        rotate_a(top);
    return ;
}

int ft_min(t_element *top)
{
    int min;

    min = top->num;
    while (top->next)
    {
        top = top->next;
        if (top->num < min)
            min = top->num;
    }
    return (min);
}

t_element *ft_last(t_element *top)
{
    while (top->next)
        top = top->next;
    return (top);
}

int find_min(t_element *top)
{
    int         min;
    int         distance;
    t_element   *temp;
    

    distance = -1;
    temp = top;
    min = ft_min(top);
    while (temp && temp->num != min)
    {
        distance++;
        temp = temp->next;
    }
    return (distance);
}

void    ft_roulette(t_element **top_a, t_element **top_b)
{
    while (t_length(*top_a) > 3 && t_check_a(*top_a) == 0)
    {
        while ((*top_a)->num != ft_min(*top_a))
        {
            //ft_printf("%d\n", ft_min(*top_a));
            //ft_printf("%d\n", find_min(*top_a));
            if ((*top_a)->num > (*top_a)->next->num)
                swap_a(top_a);
            else if ((*top_a)->num < ft_last(*top_a)->num)
            {
                reverse_rotate_a(top_a);
                swap_a(top_a);
            }
            else if (find_min(*top_a) < (t_length(*top_a) / 2))
                rotate_a(top_a);
            else if (find_min(*top_a) >= (t_length(*top_a) / 2))
                reverse_rotate_a(top_a);
        }
        push_b(top_a, top_b);
    }
}

void    ft_solve(t_element **top_a, t_element **top_b)
{
    if (t_check_a(*top_a) == 1)
        return ;
    if (t_length(*top_a) == 2)
    {
        swap_a(top_a);
        return ;
    }
    ft_roulette(top_a, top_b);
    if (t_length(*top_a) == 3 && t_check_a(*top_a) == 0)
        ft_solvethree_a(top_a);
    while ((*top_b) != NULL)
        push_a(top_a, top_b);
}
