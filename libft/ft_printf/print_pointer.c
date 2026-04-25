/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:03:59 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/29 10:04:00 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(unsigned long value, int *size)
{
	if (!value)
	{
		write(1, "(nil)", 5);
		*size += 5;
		return ;
	}
	write(1, "0x", 2);
	*size += 2;
	print_hexa(value, 'x', size);
}
