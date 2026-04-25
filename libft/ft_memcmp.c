/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:15 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/11 21:59:58 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*val1;
	const unsigned char	*val2;

	val1 = (const unsigned char *)str1;
	val2 = (const unsigned char *)str2;
	if (n == 0)
		return (0);
	while ((n - 1) > 0 && (*val1 == *val2))
	{
		val1++;
		val2++;
		n--;
	}
	return (*val1 - *val2);
}
