/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:02:42 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/28 10:23:21 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_conversion(char letter, int *size, va_list *args)
{
	if (letter == 'c')
		print_char(va_arg(*args, unsigned int), size);
	if (letter == 's')
		print_str(va_arg(*args, char *), size);
	if (letter == 'd' || letter == 'i')
		print_number(va_arg(*args, int), size);
	if (letter == 'u')
		print_unsigned(va_arg(*args, unsigned int), size);
	if (letter == 'x' || letter == 'X')
		print_hexa(va_arg(*args, unsigned int), letter, size);
	if (letter == 'p')
		print_pointer(va_arg(*args, unsigned long), size);
	if (letter == '%')
		print_char('%', size);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		size;
	int		i;

	va_start(args, string);
	size = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%' )
		{
			i++;
			check_conversion(string[i], &size, &args);
		}
		else
		{
			write(1, &string[i], 1);
			size++;
		}
		i++;
	}
	return (size);
}
