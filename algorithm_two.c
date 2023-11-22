#include "pushswap.h"

void printcosts(int len, int *costs)
{
    int j;
    
    j = 0;
    ft_printf("%s\n", "costs:");
    while (j <= len - 1)
    {
        ft_printf("%d\n", costs[j]);
        j++;
    }
}

int ft_check_t(t_element *top)
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

int ft_max(t_element *top)
{
    int max;

    max = top->num;
    while (top->next)
    {
        top = top->next;
        if (top->num > max)
            max = top->num;
    }
    return (max);
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

int ft_length(t_element *top)
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

int ft_mini(t_element *top)
{
    int min;

    min = top->num;
    while (top)
    {
        if (top->num < min)
            min = top->num;
        top = top->next;
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
    min = ft_mini(top);
    while (top)
    {
        if (top->num == min)
            index = j;
        j++;
        top = top->next;
    }
    if (index < len/2)
        return (index);
    return (len - index);
}

int rotations_dest(t_element *a, t_element *top_b, int len)
{
    long long int diff;
    int rot_b;
    int j;
    t_element *temp;

    rot_b = 0;
    j = 0;
    temp = top_b;
    diff = 4294967294;
    while (top_b)
    {
        if (a->num > top_b->num && diff > a->num - top_b->num)
        {
            rot_b = len - j;
            if (j <= len / 2)
                rot_b = j;
            diff = a->num - top_b->num;
        }
        top_b = top_b->next;
        j++;
    }
    if (diff != 4294967294)
        return (rot_b);
    return (ft_rot_min(temp, len));
}

int    *ft_find(t_element **top_a, t_element **top_b, int len)
{
    int *costs;
    register int j;
    t_element *temp;

    temp = *top_a;
    costs = malloc(len * sizeof(int));
    if (!costs)
    {
        final_free(*top_a, *top_b);
        exit(1);
    }
    j = 0;
    while (temp)
    {
        if (j <= len/2)
            costs[j] = rotations_dest(temp, *top_b, ft_length(*top_b)) + j;
        else
            costs[j] = rotations_dest(temp, *top_b, ft_length(*top_b)) + len - j;
        
        temp = temp->next;
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
    int min;

    min = ft_mini(*top);
    up = 0;
    index = 0;
    min_index = 0;
    diff = 4294967294;
    while (*top && index++)
    {
        if (elem->num > (*top)->num && diff > elem->num - (*top)->num)
        {
            up = index - 1;
            diff = elem->num - (*top)->num;
        }
        if ((*top)->num == min)
            min_index = index - 1;
        *top = (*top)->next;
    }
    ft_printf("MIN INDEX: %d\n", min_index);
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
        while (index-- > 0)
            rotate_a(top_a);
    }
    else
    {
        while (index-- > 0)
            reverse_rotate_a(top_a);
    }
    rot_dst = rotations_dest(*top_a, *top_b, len);
    uod = ft_direction(*top_a, top_b, rot_dst, len);
    while (uod == 1 && rot_dst-- > 0)
        rotate_b(top_b);
    while (uod == 0 && rot_dst-- > 0)
        reverse_rotate_b(top_b);
    push_b(top_a, top_b);
    if ((*top_a)->num == ft_mini(*top_a))
        return;
    if ((*top_a)->num > (*top_a)->next->num && (*top_a)->num != ft_max(*top_a))
        swap_a(top_a);
}

void ft_do_b(t_element **top_a, t_element **top_b, int index, int len)
{
    int rot_dst;
    int uod;

    if (index <= len/2)
    {
        while (index-- > 0)
            rotate_b(top_b);
    }
    else
    {
        while (index-- > 0)
            reverse_rotate_b(top_b);
    }
    rot_dst = rotations_dest (*top_b, *top_a, len);
    uod = ft_direction(*top_a, top_b, rot_dst, len);
    while (uod == 0 && rot_dst-- > 0)
        rotate_a(top_a);
    while (uod == 1 && rot_dst-- > 0)
        reverse_rotate_a(top_a);
    push_a(top_a, top_b);
    if ((*top_a)->num == ft_mini(*top_a))
        return;
    if ((*top_a)->num > (*top_a)->next->num && (*top_a)->num != ft_max(*top_a))
        swap_a(top_a);
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
    t_element *temp;

    temp = *top_a;
    index = 0;
    min = ft_mini(*top_a);
    while (temp && temp->num != min)
    {
        temp = temp->next;
        index++;
    }
    if (index <= ft_length(*top_a))
    {
        while (index-- > 0)
            rotate_a(top_a);
    }
    else
    {
        while (index-- > 0)
            reverse_rotate_a(top_a);
    }
}

void    ft_algorith(t_element **top_a, t_element **top_b)
{
    int *costs;
    int index;

    costs = NULL;
    index = 0;
    while (ft_length(*top_a) > 3)
    {
        if (ft_length(*top_b) < 2)
            push_b(top_a, top_b);
        else
        {
            costs = ft_find(top_a, top_b, ft_length(*top_a));
            //printcosts(ft_length(*top_a), costs);
            index = ft_index(costs, ft_length(*top_a));
            ft_do_a(top_a, top_b, index, ft_length(*top_a));
        }
        printtt(*top_a, *top_b);
    }
    ft_solvethree(top_a);
    printtt(*top_a, *top_b);
    while (ft_length(*top_b) > 0)
    {
        costs = ft_find(top_b, top_a, ft_length(*top_b));
        //printcosts(ft_length(*top_b), costs);
        index = ft_index(costs, ft_length(*top_b));
        ft_do_b(top_a, top_b, index, ft_length(*top_a));;
        printtt(*top_a, *top_b);
    }
    ft_rotate(top_a);
    printtt(*top_a, *top_b);
}

void    ft_control(t_element **top_a, t_element **top_b)
{
    if (ft_check_t(*top_a) == 1)
        return ;
    if (ft_length(*top_a) == 2)
    {
        swap_a(top_a);
        return ;
    }
    ft_algorith(top_a, top_b);
}