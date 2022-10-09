/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_scores.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:15:09 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 17:14:47 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_scores_b(t_stack *stack, int size)
{
	int	i;

	if (!stack || size == 0)
		return ;
	i = 0;
	while (i < size)
	{
		stack->rb_score = i;
		stack->rrb_score = size - i;
		i++;
		stack = stack->next;
	}
	return ;
}

static t_pattern	find_best(t_pattern current_best, t_stack *stack_b)
{
	t_pattern	new_rank;

	new_rank = fill_the_rank(stack_b);
	if (new_rank.rank < current_best.rank)
		return (new_rank);
	else
		return (current_best);
}

static t_pattern	count_scores_a(t_stack *stack_a, t_stack *stack_b, \
int size_a, int size_b)
{
	int			i;
	int			j;
	t_pattern	best_rank;

	j = 0;
	best_rank.rank = 2147483647;
	while (j < size_b)
	{
		i = 0;
		while (i < size_a)
		{
			if (stack_b->value < stack_a->value \
			&& stack_b->value > stack_a->prev->value)
			{
				stack_b->ra_score = i;
				stack_b->rra_score = size_a - i;
				best_rank = find_best(best_rank, stack_b);
			}
			i++;
			stack_a = stack_a->next;
		}
		stack_b = stack_b->next;
		j++;
	}
	return (best_rank);
}

/* The function finds best algorithm to push an element
 * from the stack b to the stack a */
t_pattern	count_scores(t_stack *stack_a, t_stack *stack_b)
{
	int			size_a;
	int			size_b;
	t_pattern	best_node;

	size_a = count_size(stack_a);
	size_b = count_size(stack_b);
	count_scores_b(stack_b, size_b);
	best_node = count_scores_a(stack_a, stack_b, size_a, size_b);
	return (best_node);
}
