/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:00:47 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/28 19:12:36 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	reverse_rotate_b(t_element **top)
{
	t_element	*temp;

	temp = *top;
	while (temp->next->next)
		temp = temp->next;
	temp->next->next = *top;
	*top = temp->next;
	temp->next = NULL;
	write(1, "rrb\n", 4);
}
