/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:05 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/12 14:13:52 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*number;
	size_t	n_length;
	int		i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	n_length = length(n);
	number = malloc(sizeof(char) * (length(n) + 1));
	if (!number)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		number[i++] = '-';
	}
	if (n == 0)
		number[0] = '0';
	number[n_length--] = '\0';
	while (n > 0)
	{
		number[n_length--] = (n % 10) + '0';
		n /= 10;
	}
	return (number);
}
