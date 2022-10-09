/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:05:06 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 17:29:24 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst2new(int value, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = new;
	new->prev = new;
	new->ra_score = -1;
	new->rra_score = -1;
	new->rb_score = -1;
	new->rrb_score = -1;
	new->value = value;
	new->flag = index;
	return (new);
}

void	ft_lst2add_back(t_stack **lst, t_stack *new)
{
	if (!(*lst))
		*lst = new;
	else
	{
		new->prev = (*lst)->prev;
		new->next = *lst;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
	}
}

void	ft_free2(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	(*lst)->prev->next = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		tmp = NULL;
	}
}

int	count_size(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 1;
	stack = stack->next;
	while (stack->flag != 0)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
