/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:44:20 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 17:24:16 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_a_type(t_stack **stack_a, t_stack **stack_b, t_pattern best_node)
{
	int	i;

	i = 0;
	while (i < best_node.rr)
	{
		do_double_rotation(stack_a, stack_b, 'y');
		i++;
	}
	i = 0;
	while (i < best_node.r)
	{
		do_rotation(stack_a, 'a');
		i++;
	}
	do_push(stack_a, stack_b, 'a');
	return ;
}

void	do_b_type(t_stack **stack_a, t_stack **stack_b, t_pattern best_node)
{
	int	i;

	i = 0;
	while (i < best_node.rr)
	{
		do_double_rotation(stack_a, stack_b, 'y');
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

void	do_c_type(t_stack **stack_a, t_stack **stack_b, t_pattern best_node)
{
	int	i;

	i = 0;
	while (i < best_node.rr)
	{
		do_double_reverse_rotation(stack_a, stack_b, 'y');
		i++;
	}
	i = 0;
	while (i < best_node.r)
	{
		do_reverse_rotation(stack_a, 'a');
		i++;
	}
	do_push(stack_a, stack_b, 'a');
	return ;
}

void	do_d_type(t_stack **stack_a, t_stack **stack_b, t_pattern best_node)
{
	int	i;

	i = 0;
	while (i < best_node.rr)
	{
		do_double_reverse_rotation(stack_a, stack_b, 'y');
		i++;
	}
	i = 0;
	while (i < best_node.r)
	{
		do_reverse_rotation(stack_b, 'b');
		i++;
	}
	do_push(stack_a, stack_b, 'a');
	return ;
}

void	do_e_type(t_stack **stack_a, t_stack **stack_b, t_pattern best_node)
{
	int	i;

	i = 0;
	while (i < best_node.rr)
	{
		do_rotation(stack_a, 'a');
		i++;
	}
	i = 0;
	while (i < best_node.r)
	{
		do_reverse_rotation(stack_b, 'b');
		i++;
	}
	do_push(stack_a, stack_b, 'a');
	return ;
}
