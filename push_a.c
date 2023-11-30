/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:59:11 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/28 19:13:27 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	push_a(t_element **top_a, t_element **top_b)
{
	t_element	*temp;

	if (*top_b != NULL)
	{
		temp = *top_b;
		*top_b = (*top_b)->next;
		temp->next = *top_a;
		*top_a = temp;
	}
	write(1, "pa\n", 3);
}
