/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:55:04 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 17:54:29 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char		**arguments;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_pattern	best_node;

	if (argc < 2)
		return (0);
	if (check_null_args(argc, argv) == 'n')
		return (write_error(NULL));
	arguments = arg_to_array(argc, argv);
	if (check_errors(arguments) == 'n')
		return (write_error(arguments));
	stack_a = fill_the_stack(arguments);
	free_char_array(arguments);
	stack_b = NULL;
	prepare_stacks(&stack_a, &stack_b);
	while (stack_b)
	{
		best_node = count_scores(stack_a, stack_b);
		push(&stack_a, &stack_b, best_node);
	}
	final_sort(&stack_a);
	ft_free2(&stack_a);
	return (0);
}
