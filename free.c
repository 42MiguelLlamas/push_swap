/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:58:22 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/30 09:43:56 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	t_free(t_element **top)
{
	t_element	*temp;

	temp = *top;
	*top = (*top)->next;
	free(temp);
}

void	final_free(t_element *top_a, t_element *top_b)
{
	while (top_a)
		t_free(&top_a);
	while (top_b)
		t_free(&top_b);
}
