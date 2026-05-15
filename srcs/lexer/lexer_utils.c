/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:45:58 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/05/13 18:40:38 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*ft_new_token(char *value, t_token_type type, char quote)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	if (!token->value)
	{
		free(token);
		return (NULL);
	}
	token->type = type;
	token->quote = quote;
	token->next = NULL;
	return (token);
}

void	ft_token_addback(t_token **head, t_token *new)
{
	t_token	*temp;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	free_tokens(t_token **token)
{
	t_token	*temp;

	if (!token || !*token)
		return ;
	temp = (*token);
	while ((*token))
	{
		temp = (*token);
		(*token) = (*token)->next;
		free(temp->value);
		free(temp);
	}
	free((*token));
	(*token) = NULL;
}
