/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_rank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:18:08 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 17:15:59 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pattern	fill_rank_straight(t_stack *stack)
{
	t_pattern	pattern;

	if (stack->rb_score > stack->ra_score)
	{
		pattern.rr = stack->ra_score;
		pattern.r = stack->rb_score - stack->ra_score;
		pattern.rank = stack->rb_score + 1;
		pattern.type = 'b';
	}
	else
	{
		pattern.rr = stack->rb_score;
		pattern.r = stack->ra_score - stack->rb_score;
		pattern.rank = stack->ra_score + 1;
		pattern.type = 'a';
	}
	return (pattern);
}

static t_pattern	fill_rank_reverse(t_stack *stack)
{
	t_pattern	pattern;

	if (stack->rrb_score > stack->rra_score)
	{
		pattern.rr = stack->rra_score;
		pattern.r = stack->rrb_score - stack->rra_score;
		pattern.rank = stack->rrb_score + 1;
		pattern.type = 'd';
	}
	else
	{
		pattern.rr = stack->rrb_score;
		pattern.r = stack->rra_score - stack->rrb_score;
		pattern.rank = stack->rra_score + 1;
		pattern.type = 'c';
	}
	return (pattern);
}

static t_pattern	fill_rank_ab(t_stack *stack)
{
	t_pattern	pattern;

	pattern.rr = stack->ra_score;
	pattern.r = stack->rrb_score;
	pattern.rank = stack->ra_score + stack->rrb_score + 1;
	pattern.type = 'e';
	return (pattern);
}

static t_pattern	fill_rank_ba(t_stack *stack)
{
	t_pattern	pattern;

	pattern.rr = stack->rra_score;
	pattern.r = stack->rb_score;
	pattern.rank = stack->rra_score + stack->rb_score + 1;
	pattern.type = 'f';
	return (pattern);
}

t_pattern	fill_the_rank(t_stack *stack)
{
	t_pattern	pattern;
	int			r;
	int			rev_r;
	int			ab;
	int			ba;

	r = number_r(stack);
	rev_r = number_rev_r(stack);
	ab = number_ab(stack);
	ba = number_ba(stack);
	if (r <= rev_r && r <= ab && r <= ba)
		pattern = fill_rank_straight(stack);
	else if (rev_r <= ab && rev_r <= ba)
		pattern = fill_rank_reverse(stack);
	else if (ab <= ba)
		pattern = fill_rank_ab(stack);
	else
		pattern = fill_rank_ba(stack);
	return (pattern);
}
