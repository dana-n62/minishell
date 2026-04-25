/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:59:08 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/29 10:29:39 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

void	print_hexa(unsigned long number, char id, int *size)
{
	unsigned long	value;
	char			*letters;
	char			temp;

	letters = "abcdef";
	value = number;
	*size += 1;
	if ((value / 16) != 0)
		print_hexa(value / 16, id, size);
	if (((number % 16) >= 10) && ((number % 16) <= 15))
	{
		if (id == 'x')
			temp = letters[(number % 16) - 10];
		if (id == 'X')
			temp = ft_toupper(letters[(number % 16) - 10]);
	}
	else
		temp = (number % 16) + 48;
	write(1, &temp, 1);
}
