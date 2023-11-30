/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:57:25 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/30 09:31:40 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	*ft_costs(t_element **top_a, t_element **top_b, int len)
{
	int				*costs;
	register int	j;
	t_element		*temp;

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
		if (j <= len / 2)
			costs[j] = r_dest(temp, *top_b, ft_length(*top_b)) + j;
		else
			costs[j] = r_dest(temp, *top_b, ft_length(*top_b)) + len - j;
		temp = temp->next;
		j++;
	}
	return (costs);
}

int	r_dest(t_element *a, t_element *tp, int len)
{
	long long int	d;
	int				rot_b;
	int				j;
	t_element		*temp;

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

int	ft_index(int *costs, int len)
{
	int	j;
	int	index;
	int	len_temp;

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

int	ft_direction(t_element *a, t_element *top, int len)
{
	int				j;
	int				index;
	int				min_index;
	long long int	diff;
	int				min;

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

int	ft_sense(int index, int min_index, int len)
{
	if (index == -1)
	{
		if (min_index <= len / 2)
			return (0);
		return (1);
	}
	if (index < len / 2)
		return (0);
	return (1);
}
