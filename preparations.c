/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:34:22 by arupert           #+#    #+#             */
/*   Updated: 2022/04/01 22:04:29 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_max(t_stack *stack, int size, int *min, int *max)
{
	*min = 2147483647;
	*max = -2147483648;
	while (size > 0)
	{
		if (*min > stack->value)
			*min = stack->value;
		if (*max < stack->value)
			*max = stack->value;
		stack = stack->next;
		size--;
	}
	return ;
}

// 1. Find min and max values
// 2. 
/* 1. Check size of the stack a;
 * 2. Transfer elements from stack a to stack b.
 * Leave no more than 3 elements in stack a;
 * 3. Sort stack a. */

static char	find_if_sorted(t_stack *stack, int min, int size)
{
	while (stack->value != min)
		stack = stack->next;
	while (--size > 0)
	{
		if (stack->value > stack->next->value)
			return ('n');
		stack = stack->next;
	}
	return ('y');
}

static void	transfer_to_b(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	int	min;
	int	max;

	find_min_max(*stack_a, size_a, &min, &max);
	*stack_b = NULL;
	if (find_if_sorted(*stack_a, min, size_a) == 'y')
		return ;
	while (size_a > 3)
	{
		if ((*stack_a)->value != min && (*stack_a)->value != max)
		{
			do_push(stack_b, stack_a, 'b');
			size_a--;
		}
		else
			do_rotation(stack_a, 'a');
	}
	return ;
}

static void	sort_a3(t_stack **stack_a)
{
	if ((*stack_a)->value < (*stack_a)->next->value && \
			(*stack_a)->next->value < (*stack_a)->prev->value)
		return ;
	if ((*stack_a)->value < (*stack_a)->next->value && \
			(*stack_a)->value > (*stack_a)->prev->value)
		return ;
	if ((*stack_a)->value > (*stack_a)->prev->value && \
			(*stack_a)->next->value < (*stack_a)->prev->value)
		return ;
	do_swap(stack_a, 'a');
	return ;
}

void	prepare_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = count_size(*stack_a);
	transfer_to_b(stack_a, stack_b, size_a);
	if (size_a > 2)
		sort_a3(stack_a);
	return ;
}
