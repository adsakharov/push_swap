/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:59:01 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 17:25:10 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_f_type(t_stack **stack_a, t_stack **stack_b, t_pattern best_node)
{
	int	i;

	i = 0;
	while (i < best_node.rr)
	{
		do_reverse_rotation(stack_a, 'a');
		i++;
	}
	i = 0;
	while (i < best_node.r)
	{
		do_rotation(stack_b, 'b');
		i++;
	}
	do_push(stack_a, stack_b, 'a');
	return ;
}

void	push(t_stack **stack_a, t_stack **stack_b, t_pattern best_node)
{
	if (best_node.type == 'a')
		do_a_type(stack_a, stack_b, best_node);
	if (best_node.type == 'b')
		do_b_type(stack_a, stack_b, best_node);
	if (best_node.type == 'c')
		do_c_type(stack_a, stack_b, best_node);
	if (best_node.type == 'd')
		do_d_type(stack_a, stack_b, best_node);
	if (best_node.type == 'e')
		do_e_type(stack_a, stack_b, best_node);
	if (best_node.type == 'f')
		do_f_type(stack_a, stack_b, best_node);
	return ;
}
