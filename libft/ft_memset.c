/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:31 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/11 12:30:24 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//arr[] == *arr is declaration but when passing the value from main
//*arr is a pointer to a read-only memory while arr[] is stacked at
//run-time so its modifiable and wont cause a SEGSEGV
void	*ft_memset(void *arr, int value, size_t length)
{
	unsigned char	*string;
	size_t			i;

	i = 0;
	string = (unsigned char *)arr;
	while (i < length)
	{
		string[i] = (unsigned char) value;
		i++;
	}
	return (arr);
}
