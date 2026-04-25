/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:57:40 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/06 12:24:17 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	s_size;
	char			*new_string;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_size = (unsigned int)ft_strlen(s);
	new_string = malloc(sizeof(char) * (s_size + 1));
	if (!new_string)
		return (NULL);
	while (i < s_size)
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
