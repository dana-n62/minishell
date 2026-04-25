/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:45:33 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/12 14:15:38 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//will be using memset as a useful tool
void	*ft_bzero(void *arr, size_t length)
{
	ft_memset(arr, '\0', length);
	return (arr);
}
