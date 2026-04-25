/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:44 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/15 10:03:45 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	clean_array(char **array_of_words, int i)
{
	while (i > 0)
		free(array_of_words[--i]);
	free(array_of_words);
}

static int	copy_word(char **array, const char *s, int *i, char c)
{
	int	word_length;

	word_length = *i;
	while (s[word_length] != c && s[word_length] != '\0')
		word_length++;
	word_length -= *i;
	*array = malloc(sizeof(char) * (word_length + 1));
	if (!*array)
		return (0);
	ft_strlcpy(*array, s + *i, word_length + 1);
	*i += word_length;
	return (1);
}

static int	split_string(char ***array_of_words, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if (!copy_word(&(*array_of_words)[j], s, &i, c))
			{
				clean_array(*array_of_words, j);
				return (0);
			}
			j++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array_of_words;
	size_t	size_of_array;

	if (!s)
		return (NULL);
	size_of_array = word_count(s, c);
	array_of_words = malloc(sizeof(char *) * (size_of_array + 1));
	if (!array_of_words)
		return (NULL);
	array_of_words[size_of_array] = NULL;
	if (!split_string(&array_of_words, s, c))
		return (NULL);
	return (array_of_words);
}
