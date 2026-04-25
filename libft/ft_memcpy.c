/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:19 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/12 11:29:09 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//remember that using void gives the program mosre flexibility with data types
//memcpy is faster than memmove because it doesn't check for overlapping
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c_dest;
	const char		*c_src;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	c_dest = (unsigned char *)dest;
	c_src = (const char *)src;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
