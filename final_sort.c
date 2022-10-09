/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:17:18 by arupert           #+#    #+#             */
/*   Updated: 2022/04/03 11:34:03 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// To find index of min element in pre-sorted list before final rotation
int	find_min_index(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack->value > stack->prev->value)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

// Do final rotation in pre-sorted list
void	final_sort(t_stack **stack)
{
	int	size;
	int	i;

	i = find_min_index(*stack);
	if (i == 1)
		return ;
	size = count_size(*stack);
	if (i - 1 <= size / 2)
		while (--i > 0)
			do_rotation(stack, 'a');
	else
		while (i++ <= size)
			do_reverse_rotation(stack, 'a');
	return ;
}
