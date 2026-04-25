/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:47 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/11 21:50:28 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*duplicate;
	size_t	str_len;

	str_len = ft_strlen(str);
	duplicate = malloc((str_len + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	ft_strlcpy(duplicate, str, str_len + 1);
	return (duplicate);
}
