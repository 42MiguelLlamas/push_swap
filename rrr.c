/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:01:54 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/28 19:08:15 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	rrr(t_element **top_a, t_element **top_b)
{
	t_element	*temp;

	temp = *top_a;
	while (temp->next->next)
		temp = temp->next;
	temp->next->next = *top_a;
	*top_a = temp->next;
	temp->next = NULL;
	temp = *top_b;
	while (temp->next->next)
		temp = temp->next;
	temp->next->next = *top_b;
	*top_b = temp->next;
	temp->next = NULL;
	write(1, "rrr\n", 4);
}
