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
    int j;
    int index;

    j = 0;
    index = 0;
    min = ft_min(top);
    while (top->next)
    {
        if (top->num == min)
            index = j;
        j++;
        top = top->next;
    }
    if (index <= len/2)
        return (index);
    return (len - index);
}

int rotations_dest(t_element *a, t_element *top_b, int len)
{
    int diff;
    int rot_b;
    int j;

    rot_b = 0;
    j = 0;
    diff = 4294967294;
    while (top_b && j++)
    {
        if (a->num - top_b->num > 0 && diff > a->num - top_b->num)
        {
            rot_b = len - j - 1;
            if (j <= len / 2)
                rot_b = j - 1;
            diff = a->num - top_b->num;
        }
        top_b = top_b->next;
    }
    if (rot_b != 0)
        return (rot_b);
    return (ft_rot_min(top_b, len));
}

int    *ft_find(t_element **top_a, t_element **top_b, int len)
{
    int *costs;
    register int j;

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
            costs[j] = rotations_dest(*top_a, *top_b, t_length(*top_b)) + j;
        else
            costs[j] = rotations_dest(*top_a, *top_b, t_length(*top_b)) + len - j;
        
        *top_a = (*top_a)->next;
        j++;
    }
    return (costs);
}

int ft_direction(t_element *elem, t_element **top, int rot_dst, int len)
{
    int up;
    int index;
    int min_index;
    long long int diff;

    up = 0;
    index = 0;
    min_index = 0;
    diff = 4294967294;
    while (*top && index++)
    {
        if (elem->num - (*top)->num > 0 && diff > elem->num - (*top)->num)
        {
            up = index - 1;
            diff = elem->num - (*top)->num;
        }
        if ((*top)->num == ft_min(*top))
            min_index = index - 1;
        *top = (*top)->next;
    }
    if ((up != 0 && up <= len / 2) || min_index == rot_dst)
        return (1);
    return (0);
}

void ft_do_a(t_element **top_a, t_element **top_b, int index, int len)
{
    int rot_dst;
    int uod;

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
    rot_dst = rotations_dest(*top_a, *top_b, len);
    uod = ft_direction(*top_a, top_b, rot_dst, len);
    while (uod == 1 && rot_dst > 0)
        rotate_b(top_b);
    while (uod == 0 && rot_dst > 0)
        reverse_rotate_b(top_b);
    push_a(top_a, top_b);
}

void ft_do_b(t_element **top_a, t_element **top_b, int index, int len)
{
    int rot_dst;
    int uod;

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
    rot_dst = rotations_dest (*top_a, *top_b, len);
    uod = ft_direction(*top_a, top_b, rot_dst, len);
    while (uod == 1 && rot_dst > 0)
        rotate_b(top_b);
    while (uod == 0 && rot_dst > 0)
        reverse_rotate_b(top_b);
    push_b(top_a, top_b);
}

int ft_index(int *costs, int len)
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
    free(costs);
    return (index);
}

void    ft_rotate(t_element **top_a)
{
    int min;
    int index;

    index = 0;
    min = ft_min(*top_a);
    while (*top_a && (*top_a)->num != min)
        index++;
    if (index <= t_length(*top_a))
    {
        while (index > 0)
            rotate_a(top_a);
        return ;
    }
    while (index > 0)
        reverse_rotate_a(top_a);
}

void    ft_algorith(t_element **top_a, t_element **top_b)
{
    int *costs;
    int index;

    costs = NULL;
    index = 0;
    while (t_length(*top_a) > 3)
    {
        if (t_length(*top_b) < 2)
            push_b(top_a, top_b);
        else
        {
            costs = ft_find(top_a, top_b, t_length(*top_a));
            index = ft_index(costs, t_length(*top_a));
            ft_do_a(top_a, top_b, index, t_length(*top_a));
        }
    }
    ft_solvethree_a(top_a);
    while (t_length(*top_b) > 0)
    {
        costs = ft_find(top_b, top_a, t_length(*top_b)) ;
        index = ft_index(costs, t_length(*top_b));
        ft_do_b(top_a, top_b, index, t_length(*top_a));;
    }
    ft_rotate(top_a);
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