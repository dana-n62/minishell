/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:14 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/06 10:47:15 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*new;
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(s1);
	new = 0;
	if (!s1 || !set)
		return (NULL);
	else
	{
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		new = (char *) malloc(j - i + 1);
		if (new)
			ft_strlcpy(new, &s1[i], j - i + 1);
	}
	return (new);
}
