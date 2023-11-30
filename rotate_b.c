/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:01:20 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/28 19:10:37 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	rotate_b(t_element **top)
{
	t_element	*temp;

	temp = *top;
	while (temp->next)
		temp = temp->next;
	temp->next = *top;
	*top = (*top)->next;
	temp->next->next = NULL;
	write(1, "rb\n", 3);
}
