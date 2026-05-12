/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:47:58 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/05/12 10:06:12 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	handle_heredoc(t_token **temp, t_cmd **current, int size)
{
	int		fd[2];
	char	*input;

	if (pipe(fd) < 0)
		return (-1);
	input = readline("");
	while (input && ft_strncmp(input, (*temp)->value, size) != 0)
	{
		write(fd[1], input, ft_strlen(input));
		write(fd[1], "\n", 1);
		free(input);
		input = readline("");
	}
	if (!input)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	free(input);
	close(fd[1]);
	(*current)->heredoc_fd = fd[0];
	return (0);
}

int	ft_handle_redir(t_token **temp, t_cmd **current)
{
	t_token_type	type;

	type = (*temp)->type;
	(*temp) = (*temp)->next;
	if (type == REDIR_IN)
	{
		(*current)->infile = ft_strdup((*temp)->value);
		if (!(*current)->infile)
			return (-1);
	}
	else if (type == HEREDOC)
	{
		if (handle_heredoc(temp, current, ft_strlen((*temp)->value)) < 0)
			return (-1);
	}
	else
	{
		if (type == REDIR_APPEND)
			(*current)->append = 1;
		(*current)->outfile = ft_strdup((*temp)->value);
		if (!(*current)->outfile)
			return (-1);
	}
	return (0);
}

int	ft_handle_word(t_token **temp, t_cmd **current)
{
	int	i;

	i = count_words(*temp);
	(*current)->args = malloc(sizeof(char *) * (i + 1));
	if (!(*current)->args)
		return (-1);
	(*current)->args[i] = NULL;
	i = 0;
	while (*temp && (*temp)->type == WORD)
	{
		(*current)->args[i] = ft_strdup((*temp)->value);
		if (!((*current)->args[i]))
			return (-1);
		i++;
		(*temp) = (*temp)->next;
	}
	return (0);
}

int	ft_handle_tokens(t_cmd **current, t_token **temp, t_cmd **head_cmd)
{
	if ((*temp)->type == WORD)
	{
		if (ft_handle_word(temp, current) < 0)
			return (-1);
	}
	else if ((*temp)->type != PIPE)
	{
		if (ft_handle_redir(temp, current) < 0)
			return (-1);
	}
	else if ((*temp)->type == PIPE)
	{
		(*current) = ft_new_cmd();
		if (!*current)
			return (-1);
		ft_cmd_addback(head_cmd, (*current));
		return (0);
	}
	return (1);
}

t_cmd	*ft_parser(t_token *tokens)
{
	t_cmd	*head_cmd;
	t_cmd	*current;
	t_token	*temp;
	int		cntinue;

	head_cmd = ft_new_cmd();
	if (!head_cmd)
		return (NULL);
	current = head_cmd;
	temp = tokens;
	while (temp)
	{
		cntinue = ft_handle_tokens(&current, &temp, &head_cmd);
		if (cntinue < 0)
		{
			ft_free_cmd(&head_cmd);
			return (NULL);
		}
		if (cntinue == 1)
			continue ;
		temp = temp->next;
	}
	return (head_cmd);
}
