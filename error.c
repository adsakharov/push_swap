/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:44:44 by arupert           #+#    #+#             */
/*   Updated: 2022/04/07 17:45:05 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	write_error(char **arguments)
{
	write(2, "Error\n", 6);
	if (arguments)
		free_char_array(arguments);
	return (-1);
}
