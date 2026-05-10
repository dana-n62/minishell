/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:19:49 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/05/04 12:14:30 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signal;

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
	(void)token_list;
	free_all(shell);
}

static void	check_input(t_shell *shell)
{
	if (shell->input == NULL)
	{
		write(1, "\n", 1);
		free_env(&shell->env);
		exit(shell->exit_status);
	}
	if (g_signal == SIGINT)
	{
		shell->exit_status = 130;
		g_signal = 0;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void) argc;
	(void) argv;
	shell.env = env_list(envp);
	if (!shell.env)
		exit(1);
	shell.cmds = NULL;
	shell.exit_status = 0;
	setup_signals();
	while (1)
	{
		check_input(&shell);
		if (shell.input[0] != '\0')
			shell_action(&shell);
	}
	return (0);
}
