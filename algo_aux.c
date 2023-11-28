#include "pushswap.h"

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