/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:32:20 by arupert           #+#    #+#             */
/*   Updated: 2022/04/03 11:35:39 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || \
			str[i] == '\t' || \
			str[i] == '\n' || \
			str[i] == '\r' || \
			str[i] == '\f' || \
			str[i] == '\v')
		i++;
	return (i);
}

long int	ft_atoi(const char *nptr)
{
	int			i;
	int			n;
	long int	x;

	i = check_space(nptr);
	n = 1;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			n = -1;
		i++;
	}
	x = 0;
	while (*(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		x = x * 10 + *(nptr + i) - 48;
		i++;
	}
	x = x * n;
	return (x);
}
