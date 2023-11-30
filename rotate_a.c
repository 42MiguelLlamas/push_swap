/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:01:05 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/28 19:09:53 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	rotate_a(t_element **top)
{
	t_element	*temp;

	temp = *top;
	while (temp->next)
		temp = temp->next;
	temp->next = *top;
	*top = (*top)->next;
	temp->next->next = NULL;
	write(1, "ra\n", 3);
}
