/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:00:29 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/28 19:11:58 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	reverse_rotate_a(t_element **top)
{
	t_element	*temp;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	temp = *top;
	while (temp->next->next)
		temp = temp->next;
	temp->next->next = *top;
	*top = temp->next;
	temp->next = NULL;
	write(1, "rra\n", 4);
}
