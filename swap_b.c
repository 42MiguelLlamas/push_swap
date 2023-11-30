/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:02:38 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/28 19:05:05 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	swap_b(t_element **top)
{
	t_element	*temp;

	if (*top != NULL && (*top)->next != NULL)
	{
		temp = (*top)->next;
		(*top)->next = temp->next;
		temp->next = *top;
		*top = temp;
	}
	write(1, "sb\n", 3);
}
