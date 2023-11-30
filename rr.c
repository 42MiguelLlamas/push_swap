/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:01:37 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/28 19:09:13 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	rr(t_element **top_a, t_element **top_b)
{
	t_element	*temp;

	temp = *top_a;
	while (temp->next)
		temp = temp->next;
	temp->next = *top_a;
	*top_a = (*top_a)->next;
	temp->next->next = NULL;
	temp = *top_b;
	while (temp->next)
		temp = temp->next;
	temp->next = *top_b;
	*top_b = (*top_b)->next;
	temp->next->next = NULL;
	write(1, "rr\n", 3);
}
