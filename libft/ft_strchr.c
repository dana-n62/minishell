/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:39 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/12 14:14:41 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//finds the given characters location and return the string starting there
char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	if ((char)c == 0)
		return ((char *)str + ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
// int main()
// {
// 	printf("%s\n",ft_strchr("teste", 'e'));
// 	printf("%s\n",ft_strchr("teste", '\0'));
// 	printf("%s\n",strchr("teste", 'e'));
// 	printf("%s\n",strchr("teste", '\0'));
// }
