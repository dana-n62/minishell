/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:10 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/12 13:21:34 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*c_str;
	size_t		i;

	c_str = (const char *)str;
	i = 0;
	while (i < n)
	{
		if (c_str[i] != (char)c)
			i++;
		else
			return ((char *)str + i);
	}
	return (NULL);
}
