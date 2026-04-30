/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:42:11 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/04/28 11:39:41 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_env(t_env **env)
{
	t_env	*temp;

	if (!env || !*env)
		return ;
	while ((*env) != NULL)
	{
		temp = *env;
		(*env) = (*env)->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

t_env	*ft_new_env(char *envp)
{
	t_env	*new_env;
	char	*equal_sign;
	int		length;

	new_env = ft_calloc(1, sizeof(t_env));
	if (!new_env)
		return (NULL);
	equal_sign = ft_strchr(envp, '=');
	length = equal_sign - envp;
	new_env->key = ft_substr(envp, 0, length);
	if (!new_env->key)
	{
		free(new_env);
		return (NULL);
	}
	new_env->value = ft_substr(envp, length + 1, ft_strlen(envp) - length - 1);
	if (!new_env->value)
	{
		free(new_env->key);
		free(new_env);
		return (NULL);
	}
	new_env->next = NULL;
	return (new_env);
}

t_env	*env_list(char **envp)
{
	t_env	*head;
	t_env	*new;
	t_env	*last;
	int		i;

	head = NULL;
	last = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		new = ft_new_env(envp[i]);
		if (!new)
		{
			free_env(&head);
			return (NULL);
		}
		if (i == 0)
			head = new;
		else
			last->next = new;
		last = new;
		i++;
	}
	return (head);
}
