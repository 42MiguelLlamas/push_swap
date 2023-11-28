#include "pushswap.h"

/*
void printcosts(int len, int *costs)
{
    int j;
    
    j = 0;
    ft_printf("\n%s\n", "costs:");
    while (j <= len - 1)
    {
        ft_printf("%d ", costs[j]);
        j++;
    }
}*/

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
    while (top && top->next)
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
    min = ft_mini(top);
    while (top)
    {
        if (top->num == min)
        {
            index = j;
            break;
        }
        j++;
        top = top->next;
    }
    if (index <= len/2)
        return (index);
    return (len - index);
}

int rotations_dest(t_element *a, t_element *tp, int len)
{
    long long int d;
    int rot_b;
    int j;
    t_element *temp;

    j = 0;
    temp = tp;
    d = 4294967294;
    while (tp)
    {
        if (a->num > tp->num && d > (long long)a->num - (long long)tp->num)
        {
            rot_b = len - j - 1;
            if (j < len / 2)
                rot_b = j + 1;
            d = (long long int)a->num - (long long int)tp->num;
        }
        tp = tp->next;
        j++;
    }
    if (d != 4294967294)
        return (rot_b);
    return (ft_rot_min(temp, len));
}

int    *ft_costs(t_element **top_a, t_element **top_b, int len)
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

int ft_sense(int index, int min_index, int len)
{  
    if (index == -1)
    {
        if (min_index <= len/2)
            return (0);
        return (1);
    }
    if (index < len/2)
        return (0);
    return (1);
}

int ft_direction(t_element *a, t_element *top, int len)
{
    int j;
    int index;
    int min_index;
    long long int diff;
    int min;

    j = 0;
    min = ft_mini(top);
    index = -1;
    min_index = 0;
    diff = 4294967296;
    while (top)
    {
        if (a->num > top->num && diff > (long long)a->num - (long long)top->num)
        {
            index = j;
            diff = (long long)a->num - (long long)top->num;
        }
        if (top->num == min)
            min_index = j;
        top = top->next;
        j++;
    }
    return (ft_sense(index, min_index, len));  
}
/*
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
    uod = ft_direction(*top_a, *top_b, len);
    while (uod == 0 && rot_dst-- > 0)
        rotate_b(top_b);
    while (uod == 1 && rot_dst-- > 0)
        reverse_rotate_b(top_b);
    push_b(top_a, top_b);
    if ((*top_b)->num == ft_mini(*top_b))
        return;
    swap_b(top_b);
}*/

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
    //ft_printf("Rot dest: %d\n", rot_dst);
    while (uod == 0 && rot_dst-- > 0)
        rotate_a(top_a);
    while (uod == 1 && rot_dst-- > 0)
        reverse_rotate_a(top_a);
    push_a(top_a, top_b);
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
        if (costs[len_temp - 1] <= j)
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

void    ft_algorith(t_element **top_a, t_element **top_b)
{
    int *costs;
    int index;

    costs = NULL;
    index = 0;
    while (ft_length(*top_a) > 3)
        push_b(top_a, top_b);
    ft_solvethree(top_a);
    //printtt(*top_a, *top_b);
    while (ft_length(*top_b) > 0)
    {
        costs = ft_costs(top_b, top_a, ft_length(*top_b));
        //printcosts(ft_length(*top_b), costs);
        index = ft_index(costs, ft_length(*top_b));
        ft_do_b(top_a, top_b, index, ft_length(*top_a), ft_length(*top_b));
        //printtt(*top_a, *top_b);
    }
    ft_rotate(top_a);
    //printtt(*top_a, *top_b);
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