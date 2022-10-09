/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:38:18 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 17:13:03 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_r(t_stack *stack)
{
	if (stack->rb_score > stack->ra_score)
		return (stack->rb_score + 1);
	else
		return (stack->ra_score + 1);
}

int	number_rev_r(t_stack *stack)
{
	if (stack->rrb_score > stack->rra_score)
		return (stack->rrb_score + 1);
	else
		return (stack->rra_score + 1);
}

int	number_ab(t_stack *stack)
{
	return (stack->rrb_score + stack->ra_score + 1);
}

int	number_ba(t_stack *stack)
{
	return (stack->rb_score + stack->rra_score + 1);
}
