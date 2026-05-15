/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:56:18 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/05/15 14:27:35 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*ft_new_cmd(void)
{
	t_cmd	*new_cmd;

	new_cmd = ft_calloc(1, sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->heredoc_fd = -1;
	return (new_cmd);
}

void	ft_cmd_addback(t_cmd **head, t_cmd *new)
{
	t_cmd	*temp;

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

void	ft_free_cmd(t_cmd **head)
{
	t_cmd	*temp;
	int		i;

	if (!head || !*head)
		return ;
	while (*head)
	{
		temp = *head;
		i = 0;
		while (temp->args && temp->args[i])
		{
			free(temp->args[i]);
			i++;
		}
		free(temp->args);
		if (temp->infile)
			free(temp->infile);
		if (temp->outfile)
			free(temp->outfile);
		*head = (*head)->next;
		free(temp);
	}
}

int	count_words(t_token *temp)
{
	int	words;

	words = 0;
	while (temp && temp->type == WORD)
	{
		words++;
		temp = temp->next;
	}
	return (words);
}
