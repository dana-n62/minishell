/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 09:55:40 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/05/15 14:09:04 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_get_redir(t_token **temp, char *op)
{
	if (op[0] == op[1])
	{
		(*temp)->value = ft_strdup(op);
		if (op[0] == '>')
			(*temp)->type = REDIR_APPEND;
		if (op[0] == '<')
			(*temp)->type = HEREDOC;
		return (2);
	}
	else
	{
		if (op[0] == '<')
		{
			(*temp)->value = ft_strdup("<");
			(*temp)->type = REDIR_IN;
		}
		if (op[0] == '>')
		{
			(*temp)->value = ft_strdup(">");
			(*temp)->type = REDIR_OUT;
		}
		return (1);
	}
	return (0);
}

t_token	*ft_get_operator(char *input, int *i)
{
	t_token	*temp;
	char	op[3];

	temp = ft_calloc(1, sizeof(t_token));
	if (!temp)
		return (NULL);
	op[0] = input[*i];
	op[1] = input[*i + 1];
	op[2] = '\0';
	if (op[0] == '|')
	{
		temp->value = ft_strdup("|");
		temp->type = PIPE;
		(*i)++;
	}
	else
		(*i) += ft_get_redir(&temp, op);
	return (temp);
}

void	ft_get_quote(t_token **temp, char *input, int current, int *i)
{
	int	x;

	(*temp)->quote = input[current];
	x = current++;
	while (input[current] && input[current] != input[x])
		current++;
	*i = current + 1;
	(*temp)->value = ft_substr(input, x + 1, current - x - 1);
	if (!(*temp)->value)
		free((*temp));
}

t_token	*ft_get_word(char *input, int *i)
{
	t_token	*temp;
	int		crnt;

	temp = ft_calloc(1, sizeof(t_token));
	if (!temp)
		return (NULL);
	crnt = *i;
	temp->type = WORD;
	while (input[crnt] != ' ' && input[crnt] != '\0')
	{
		if (input[crnt] == '|' || input[crnt] == '<' || input[crnt] == '>')
			break ;
		if (input[crnt] == '"' || input[crnt] == '\'')
		{
			ft_get_quote(&temp, input, crnt, i);
			return (temp);
		}
		crnt++;
	}
	temp->value = ft_substr(input, *i, crnt - *i);
	if (!temp->value)
		free_tokens(&temp);
	(*i) = crnt;
	return (temp);
}

t_token	*ft_lexer(char *input)
{
	int		i;
	t_token	*head;
	t_token	*next;

	i = 0;
	head = NULL;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
		{
			i++;
			continue ;
		}
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			next = ft_get_operator(input, &i);
		else
			next = ft_get_word(input, &i);
		ft_token_addback(&head, next);
	}
	return (head);
}
