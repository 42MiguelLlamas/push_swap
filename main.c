/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:58:44 by mllamas-          #+#    #+#             */
/*   Updated: 2023/11/30 09:42:48 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	main(int argc, char **argv)
{
	register int	i;
	t_element		*top_a_stack;
	t_element		*top_b_stack;

	if (argc < 2)
		return (1);
	i = 0;
	while (argv[++i])
		ft_check(i, argv);
	top_a_stack = NULL;
	while (--argc)
		top_a_stack = t_insert(top_a_stack, ft_atoi(argv[argc]));
	top_b_stack = NULL;
	ft_control(&top_a_stack, &top_b_stack);
	final_free(top_a_stack, top_b_stack);
	return (0);
}
