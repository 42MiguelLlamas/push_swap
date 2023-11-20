#include "pushswap.h"

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

int ft_rot_min(t_element *top, int len)
{
    int min;
    int rot;
    int j;
    int index;

    rot = 0;
    j = 0;
    index = 0;
    min = ft_min(top);
    while (top->next)
    {
        if (top->num = min)
            index = j;
        j++;
        top = top->next;
    }
    if (index <= len/2)
        return (index)
    return (len - index);
}

int rotations_b(t_element *a, , t_element *top_b)
{
    int diff;
    int rot_b;
    int j;
    t_element *temp;

    temp = top_b;
    rot_b = 0;
    j = -1;
    diff = num - temp->num;
    if (a->num > ft_min(top_b))
    {
        while (temp && j++)
        {
            if (diff > 0 && diff > a->num - temp->num)
            {
                rot_b = t_length(top_b) - j;
                if (j <= t_length(top_b) / 2)
                    rot_b = j;      
            }
            temp = temp->next;
        }
        return (rot_b);
    }
    return (ft_rot_min(top_b, t_length(top_b)));
}

int    *ft_costs(t_element **top_a, , t_element **top_b)
{
    int *costs;
    register int j;
    int len;

    len = t_length(*top_a)
    costs = malloc(len * sizeof(int));
    if (!costs)
    {
        final_free(*top_a, *top_b);
        exit(1);
    }
    j = 0;
    while (*top_a)
    {
        if (j <= len/2)
            rotations_a = j;
        else
            rotations_a = len - j;
        costs[j] = rotations_b(*top_a, *top_b) + rotations_a;
        *top_a = (*top_a)->next;
        j++;
    }
    return (costs);
}

void ft_do_other(int num, t_element **top)
{
    int diff;
    t_element *temp;
    int *uod;

    uod = malloc(sizeof(int));
    if (!uod)
    {
        final_free(*top_a, *top_b);
        exit(1);
    }
    uod = 0;
    temp = *top;
    if (num > ft_min(*top))
    {
        while (temp && j++)
        {
            diff = num - (*top)->num;
            if (diff > 0 && diff > num - temp->num)
            {
                rot_b = t_length(*top) - j;
                up_or_down = 0;
                if (j <= t_length(*top) / 2)
                {
                    rot_b = j;
                    up_or_down = 1;
                }      
            }
            temp = temp->next;
        }
    }
    else
    rot_b = ft_rot_min(top_b, t_length(*top));

    }
}
void ft_do_a(t_element **top_a, , t_element **top_b, int index, int len)
{
    if (index <= len/2)
    {
        while (index > 0)
            rotate_a(top_a);
    }
    else
    {
        while (index > 0)
            reverse_rotate_a(top_a);
    }
    ft_do_other((*top_a)->num, top_b);
    push_a(top_a, top_b);

}

void ft_do_b(t_element **top_a, , t_element **top_b, int index, int len)
{
    if (index <= len/2)
    {
        while (index > 0)
            rotate_b(top_b);
    }
    else
    {
        while (index > 0)
            reverse_rotate_b(top_b);
    }
    ft_do_other((*top_b)->num, top_a);
    push_b(top_a, top_b);
}

void ft_do(t_element **top_a, , t_element **top_b, int *costs, int len, int a_or_b)
{
    int j;
    int index;
    int len_temp;

    len_temp = len;
    index = 0;
    j = costs[0];
    while (len_temp > 0)
    {
        if (costs[len_temp - 1] < j)
        {
            j = costs[len_temp - 1];
            index = len_temp - 1; 
        }
        len_temp--;
    }
    if (a_or_b = 1)
        ft_do_a(top_a, top_b, index, len, j);
    else
        ft_do_b(top_a, top_b, index, len, j);
}

void    ft_algorith(t_element **top_a, , t_element **top_b)
{
    int *costs;

    costs = NULL;
    while (t_length(*top_a) > 3)
    {
        if (t_length(*top_b) < 2)
            push_b(top_a, top_b);
        else
        {
            costs = ft_find(top_a, top_b);
            ft_do(top_a, top_b, costs, t_length(*top_a), 1);
        }
    }
    ft_solvethree_a(top_a);
    while (t_length(*top_b) > 0)
    {
        costs = ft_find(top_b, top_a);
        ft_do(top_a, top_b, costs, t_length(*top_b), 0);
    }
}

void    ft_control(t_element **top_a, t_element **top_b)
{
    if (t_check_a(*top_a) == 1)
        return ;
    if (t_length(*top_a) == 2)
    {
        swap_a(top_a);
        return ;
    }
    ft_algorith(top_a, top_b);
}