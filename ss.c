/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:02:09 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/28 19:07:04 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ss(t_element **top_a, t_element **top_b)
{
	t_element	*temp;

	if (*top_a != NULL && (*top_a)->next != NULL)
	{
		temp = (*top_a)->next;
		(*top_a)->next = temp->next;
		temp->next = *top_a;
		*top_a = temp;
	}
	if (*top_b != NULL && (*top_b)->next != NULL)
	{
		temp = (*top_b)->next;
		(*top_b)->next = temp->next;
		temp->next = *top_b;
		*top_b = temp;
	}
	write(1, "ss\n", 3);
}
