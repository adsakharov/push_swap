/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:49:37 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 17:22:15 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotation(t_stack **stack, char to_print)
{
	(*stack)->next->flag = 0;
	(*stack)->flag = 1;
	(*stack) = (*stack)->next;
	if (to_print == 'a')
		ft_putstr_fd("ra\n", 1);
	if (to_print == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	do_double_rotation(t_stack **stack1, t_stack **stack2, char to_print)
{
	do_rotation(stack1, 'n');
	do_rotation(stack2, 'n');
	if (to_print == 'y')
		ft_putstr_fd("rr\n", 1);
}

void	do_reverse_rotation(t_stack **stack, char to_print)
{
	(*stack)->prev->flag = 0;
	(*stack)->flag = 1;
	(*stack) = (*stack)->prev;
	if (to_print == 'a')
		ft_putstr_fd("rra\n", 1);
	if (to_print == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	do_double_reverse_rotation(t_stack **stack1, \
		t_stack **stack2, char to_print)
{
	do_reverse_rotation(stack1, 'n');
	do_reverse_rotation(stack2, 'n');
	if (to_print == 'y')
		ft_putstr_fd("rrr\n", 1);
}
