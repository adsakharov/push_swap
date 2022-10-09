/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:31:02 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 18:02:23 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_symbols_and_length(char *word)
{
	int	i;
	int	j;

	i = check_space(word);
	if (word[i] && (word[i] == '+' || word[i] == '-'))
		i++;
	j = 0;
	while (word[i + j])
	{
		if (!ft_isdigit(word[i + j]))
			return (-1);
		j++;
	}
	if (j > 10)
		return (-1);
	return (i);
}

static char	check_long_int(char **array, int index)
{
	long int	x;
	int			i;

	i = 0;
	x = ft_atoi(array[index]);
	if (x > 2147483647 || x < -2147483648)
		return ('n');
	return ('y');
}

static char	check_duplicates(char **array, int index)
{
	long int	x;

	x = ft_atoi(array[index]);
	while (array[++index])
		if (x == ft_atoi(array[index]))
			return ('n');
	return ('y');
}

char	check_errors(char **array)
{
	int	i;

	if (!array)
		return ('n');
	i = 0;
	while (*(array + i))
	{
		if (check_symbols_and_length(array[i]) < 0)
			return ('n');
		if (check_long_int(array, i) == 'n')
			return ('n');
		i++;
	}
	i = 0;
	while (*(array + i))
	{
		if (check_duplicates(array, i) == 'n')
			return ('n');
		i++;
	}
	return ('y');
}

char	check_null_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return ('n');
		i++;
	}
	return ('y');
}
