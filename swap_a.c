/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:02:24 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/28 19:05:50 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	swap_a(t_element **top)
{
	t_element	*temp;

	if (*top != NULL && (*top)->next != NULL)
	{
		temp = (*top)->next;
		(*top)->next = temp->next;
		temp->next = *top;
		*top = temp;
	}
	write(1, "sa\n", 3);
}
