/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:19:24 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 19:44:16 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(dst + i) != '\0' && i < size)
		i++;
	j = 0;
	while (*(src + j) != '\0' && size > (i + j + 1))
	{
		*(dst + i + j) = *(src + j);
		j++;
	}
	if (i + j < size)
		*(dst + i + j) = '\0';
	return (i + ft_strlen(src));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (*str1 == '\0' || *str2 == '\0')
		return (*str1 - *str2);
	i = 0;
	while ((*(str1 + i) != '\0' && *(str2 + i) != '\0'))
	{
		if (*(str1 + i) == *(str2 + i))
			i++;
		else
			return (*(str1 + i) - *(str2 + i));
	}
	return (*(str1 + i) - *(str2 + i));
}
