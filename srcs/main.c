/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:19:49 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/04/30 08:35:52 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_all(t_shell *shell)
{
	if (shell && shell->cmds)
		shell->cmds = NULL;
	if (shell && shell->input)
		free(shell->input);
}

void	shell_action(t_shell *shell)
{
	t_token	*token_list;

	add_history(shell->input);
	(void)token_list;// = ft_lexer(shell->input);
	free_all(shell);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	t_shell	shell;

	shell.env = env_list(envp);
	if (!shell.env)
		exit(1);
	shell.cmds = NULL;
	shell.exit_status = 0;
	while (1)
	{
		shell.input = readline("minishell$");
		if (shell.input == NULL)
		{
			write(1, "\n", 1);
			free_env(&shell.env);
			exit(shell.exit_status);
		}
		if (shell.input[0] != '\0')
			shell_action(&shell);
	}
	return (0);
}
