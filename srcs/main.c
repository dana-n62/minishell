/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:19:49 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/05/15 14:12:22 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signal;

void	free_all(t_shell *shell)
{
	if (shell && shell->cmds)
		ft_free_cmd(&shell->cmds);
	if (shell && shell->input)
		free(shell->input);
}

void	shell_action(t_shell *shell)
{
	t_token	*token_list;

	add_history(shell->input); /*add the line to the history for future retreveal using arrows*/
	token_list = ft_lexer(shell->input); /*tokinization in action*/
	if (!token_list)
		return ;
	shell->cmds = ft_parser(token_list); /*understanding what each token supposed to do, redirecting and piping*/
	free_tokens(&token_list); /*whether cmds worked or not tokens need to be freed after they are used*/
}

static void	check_input(t_shell *shell)
{
	if (shell->input == NULL)
	{
		write(1, "\n", 1); /*if something went wrong all need to be cleared up*/
		free_env(&shell->env);
		free_all(shell);
		exit(shell->exit_status);
	}
	if (g_signal == SIGINT)
	{
		shell->exit_status = 130; /*exit status will be used for later reference*/
		g_signal = 0; /*setting it back to 0 so it can be switched back on when needed*/
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell; /*the container of it all*/
	
	(void) argc;
	(void) argv;
	shell.env = env_list(envp); /*create an easy to manipulate list of all the variables for this session*/
	if (!shell.env)
		exit(1);
	shell.cmds = NULL; /*initialization*/
	shell.exit_status = 0;
	setup_signals(); /*this is needed to ignor the quit signal that will exit the minishell, and to handle the sigint within it*/
	while (1)
	{
		shell.input = readline("minishell$ "); /*start the process*/
		check_input(&shell); /*testing the input*/
		if (shell.input[0] != '\0')
			shell_action(&shell); /*the actual reading of the input content*/
		free_all(&shell);
	}
	return (0);
}
