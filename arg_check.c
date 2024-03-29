/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:57:45 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/30 09:34:28 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	ft_atoi(char *argv)
{
	int			sign;
	long int	num;

	sign = 1;
	if (*argv == '-')
	{
		sign = -sign;
		argv++;
	}
	else if (*argv == '+')
		argv++;
	if (!(*argv))
		ft_exit();
	num = 0;
	while (*argv >= '0' && *argv <= '9')
	{
		num = num * 10;
		num = num + (*argv - '0');
		argv++;
	}
	if ((num * sign) < -2147483648 || (num * sign) > 2147483647)
		ft_exit();
	return (num * sign);
}

void	ft_check(const int index, char **argv)
{
	register int	j;

	j = 0;
	if (ft_strlen(argv[index]) == 0)
		ft_exit();
	if (argv[index][j] == '-' || argv[index][j] == '+')
		j++;
	while (argv[index][j])
	{
		if (argv[index][j] >= '0' && argv[index][j] <= '9')
			j++;
		else
			ft_exit();
	}
	j = 0;
	while (argv[++j])
	{
		if (ft_atoi(argv[index]) == ft_atoi(argv[j]) && j != index)
			ft_exit();
	}
}

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (*s)
	{
		a++;
		s++;
	}
	return (a);
}

t_element	*t_insert(t_element *top, int number)
{
	t_element	*temp;

	temp = malloc(sizeof(t_element));
	if (!temp)
	{
		while (top)
			t_free(&top);
		return (NULL);
	}
	temp->num = number;
	temp->next = top;
	top = temp;
	return (top);
}

/*void printtt(t_element *top_a_stack, t_element *top_b_stack)
{
    t_element       *temp;

    temp = top_a_stack;
    ft_printf("%s\n", "Stack A:");
    while (temp)
    {
        ft_printf("%d ", temp->num);
        temp = temp->next;
    }
    temp = top_b_stack;
    ft_printf("\n%s\n", "Stack B:");
    while (temp)
    {
        ft_printf("%d ", temp->num);
        temp = temp->next;
    }
}*/
