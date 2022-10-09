/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:42:58 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 17:11:59 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**arg_to_array(int argc, char **argv)
{
	char	**arguments;
	int		i;

	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	if (argc > 2)
	{
		arguments = (char **)malloc(sizeof(char *) * argc);
		if (arguments == NULL)
			return (NULL);
		i = 0;
		while ((i + 1) < argc)
		{
			arguments[i] = ft_strdup(argv[i + 1]);
			if (arguments == NULL)
				return (free_char_array(arguments));
			i++;
		}
		arguments[i] = NULL;
	}
	return (arguments);
}

t_stack	*fill_the_stack(char **arguments)
{
	int		i;
	t_stack	*stack;
	t_stack	*new;

	i = 0;
	stack = NULL;
	while (arguments[i])
	{
		new = ft_lst2new(ft_atoi(arguments[i]), i);
		if (!new)
		{
			ft_free2(&stack);
			return (NULL);
		}
		ft_lst2add_back(&stack, new);
		i++;
	}
	return (stack);
}
