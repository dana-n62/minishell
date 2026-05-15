/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:10:46 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/05/15 13:48:32 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handler(int sig) /*handling ctrl+c*/
{
	g_signal = sig; /*giving it a value as a switch*/
	write(1, "\n", 1);
	rl_on_new_line(); /*place mark on new line*/
	rl_replace_line("", 0); /*display nothing on it*/
	rl_redisplay(); /*restart readline*/
}

void	setup_signals(void)
{
	struct sigaction	sa;
	struct sigaction	sa_quit;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa_quit.sa_handler = SIG_IGN;
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa_quit, NULL);
}
