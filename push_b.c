/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:59:29 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/28 19:14:13 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	push_b(t_element **top_a, t_element **top_b)
{
	t_element	*temp;

	if (*top_a != NULL)
	{
		temp = *top_a;
		*top_a = (*top_a)->next;
		temp->next = *top_b;
		*top_b = temp;
	}
	write(1, "pb\n", 3);
}
