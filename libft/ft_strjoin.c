/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:52 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/06 10:46:53 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_length;
	size_t	s2_length;

	if (!s1 ||!s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	new_string = malloc(s1_length + s2_length + 1);
	if (!new_string)
		return (NULL);
	new_string[0] = '\0';
	ft_strlcat(new_string, s1, s1_length + 1);
	ft_strlcat(new_string + s1_length, s2, s2_length + 1);
	return (new_string);
}
