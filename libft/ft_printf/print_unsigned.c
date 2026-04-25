/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:15:54 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/29 10:31:26 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(int val_unsigned, int *size)
{
	long long		value;
	char			temp;

	value = (long long)val_unsigned;
	*size += 1;
	if (value == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (value < 0)
		value = UINT_MAX + (value + 1);
	if (value / 10 != 0)
		print_unsigned(value / 10, size);
	temp = value % 10 + 48;
	write(1, &temp, 1);
}
