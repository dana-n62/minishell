/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:45:38 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/12 12:55:09 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//always check for malloc if worked or not
void	*ft_calloc(size_t number, size_t size)
{
	void	*array;

	if (number == 0 && size == 0)
	{
		number = 1;
		size = 1;
	}
	array = malloc(number * size);
	if (!array)
		return (NULL);
	ft_bzero(array, number * size);
	return (array);
}
