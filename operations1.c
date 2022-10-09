/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:53:53 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 17:21:12 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_stack **stack, char to_print)
{
	(*stack)->flag = 1;
	(*stack)->next->flag = 0;
	(*stack)->next = (*stack)->next->next;
	(*stack)->next->prev->prev = (*stack)->prev;
	(*stack)->next->prev->next = (*stack);
	(*stack)->prev = (*stack)->next->prev;
	(*stack)->next->prev = (*stack);
	(*stack)->prev->prev->next = (*stack)->prev;
	(*stack) = (*stack)->prev;
	if (to_print == 'a')
		ft_putstr_fd("sa\n", 1);
	if (to_print == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	do_double_swap(t_stack **stack_a, t_stack **stack_b, char to_print)
{
	do_swap(stack_a, 'n');
	do_swap(stack_b, 'n');
	if (to_print == 'y')
		ft_putstr_fd("ss\n", 1);
}

/* push the top element from a stack 2 to a stack 1
 * if there is no elements in a stack 1 */

static void	do_null_push(t_stack **stack1, t_stack **stack2)
{
	(*stack2)->next->flag = 0;
	(*stack2)->next->prev = (*stack2)->prev;
	(*stack2)->prev->next = (*stack2)->next;
	(*stack1) = (*stack2);
	(*stack2) = (*stack2)->next;
	(*stack1)->next = (*stack1);
	(*stack1)->prev = (*stack1);
}

/* push the very last element from a stack 2 to a stack 1*/

static void	do_push_null(t_stack **stack1, t_stack **stack2)
{
	(*stack2)->next = (*stack1);
	(*stack2)->prev = (*stack1)->prev;
	(*stack1)->flag = 1;
	(*stack2)->flag = 0;
	(*stack1)->prev->next = *stack2;
	(*stack1)->prev = *stack2;
	(*stack1) = (*stack1)->prev;
	*stack2 = NULL;
}

/* push a top element from a stack 2 to a stack 1 */

void	do_push(t_stack **stack1, t_stack **stack2, char to_print)
{
	t_stack	*tmp;

	if (!(*stack1))
		do_null_push(stack1, stack2);
	else if ((*stack2)->next == *stack2)
		do_push_null(stack1, stack2);
	else
	{
		(*stack2)->next->flag = 0;
		(*stack1)->flag = 1;
		(*stack1)->prev->next = (*stack2);
		(*stack2)->prev->next = (*stack2)->next;
		(*stack2)->next->prev = (*stack2)->prev;
		(*stack2)->prev = (*stack1)->prev;
		(*stack1)->prev = (*stack2);
		tmp = (*stack2)->next;
		(*stack2)->next = (*stack1);
		(*stack1) = (*stack2);
		(*stack2) = tmp;
	}
	if (to_print == 'a')
		ft_putstr_fd("pa\n", 1);
	if (to_print == 'b')
		ft_putstr_fd("pb\n", 1);
}
