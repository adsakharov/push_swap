/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:25:00 by arupert           #+#    #+#             */
/*   Updated: 2022/07/09 22:27:11 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_1_instruction(char (*instruction)[5])
{
	int		num_of_read;
	char	buf[2];
	int		i;

	num_of_read = read(0, buf, 1);
	buf[1] = '\0';
	(*instruction)[0] = '\0';
	i = 0;
	while (num_of_read > 0 && i < 4 && buf[0] != '\n')
	{
		ft_strlcat(*instruction, buf, 5);
		i++;
		num_of_read = read(0, buf, 1);
	}
	if (i > 3)
		return (-1);
	return (num_of_read);
}

static int	do_operation(t_stack **stack_a, t_stack **stack_b, \
char *instruction)
{
	if (ft_strcmp(instruction, "sa") == 0 && *stack_a)
		do_swap(stack_a, 'n');
	else if (ft_strcmp(instruction, "sb") == 0 && *stack_b)
		do_swap(stack_b, 'n');
	else if (ft_strcmp(instruction, "ss") == 0 && *stack_a && *stack_b)
		do_double_swap(stack_a, stack_b, 'n');
	else if (ft_strcmp(instruction, "pa") == 0 && *stack_b)
		do_push(stack_a, stack_b, 'n');
	else if (ft_strcmp(instruction, "pb") == 0 && *stack_a)
		do_push(stack_b, stack_a, 'n');
	else if (ft_strcmp(instruction, "ra") == 0 && *stack_a)
		do_rotation(stack_a, 'n');
	else if (ft_strcmp(instruction, "rb") == 0 && *stack_b)
		do_rotation(stack_b, 'n');
	else if (ft_strcmp(instruction, "rr") == 0 && *stack_a && *stack_b)
		do_double_rotation(stack_a, stack_b, 'n');
	else if (ft_strcmp(instruction, "rra") == 0 && *stack_a)
		do_reverse_rotation(stack_a, 'n');
	else if (ft_strcmp(instruction, "rrb") == 0 && *stack_b)
		do_reverse_rotation(stack_b, 'n');
	else if (ft_strcmp(instruction, "rrr") == 0 && *stack_a && *stack_b)
		do_double_reverse_rotation(stack_a, stack_b, 'n');
	else
		return (-1);
	return (1);
}

static void	check_if_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	if (*stack_b)
	{
		ft_putstr_fd("KO\n", 1);
		ft_free2(stack_b);
		return ;
	}	
	size_a = count_size(*stack_a);
	if ((*stack_a)->value > (*stack_a)->prev->value)
		ft_putstr_fd("KO\n", 1);
	else
	{
		while (--size_a > 0)
		{
			*stack_a = (*stack_a)->next;
			if ((*stack_a)->value < (*stack_a)->prev->value)
			{
				ft_putstr_fd("KO\n", 1);
				return ;
			}
		}
		ft_putstr_fd("OK\n", 1);
	}
	return ;
}

static void	check_instructions(t_stack **stack_a)
{
	t_stack	*stack_b;
	char	instruction[5];
	int		num_of_read;

	stack_b = NULL;
	num_of_read = read_1_instruction(&instruction);
	while (num_of_read > 0)
	{
		if (do_operation(stack_a, &stack_b, instruction) < 1)
		{
			if (stack_b)
				ft_free2(&stack_b);
			write(2, "Error\n", 6);
			return ;
		}
		num_of_read = read_1_instruction(&instruction);
	}
	if (num_of_read < 0)
	{
		if (stack_b)
			ft_free2(&stack_b);
		write(2, "Error\n", 6);
		return ;
	}
	check_if_sorted(stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	char		**arguments;
	t_stack		*stack_a;

	if (argc < 2)
		return (0);
	if (check_null_args(argc, argv) == 'n')
		return (write_error(NULL));
	arguments = arg_to_array(argc, argv);
	if (check_errors(arguments) == 'n')
		return (write_error(arguments));
	stack_a = fill_the_stack(arguments);
	arguments = free_char_array(arguments);
	check_instructions(&stack_a);
	if (stack_a)
		ft_free2(&stack_a);
	return (0);
}
