/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:13:39 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/04/25 14:21:09 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
/* # include <unistd.h>
# include <stdio.h>
# include <sys/wait.h> */
/*can be used throughout the program since its in the header */
extern int	g_signal;
/* the enviromental variable value */
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;
/* the command ordered by user, each line gets one node */
typedef struct s_cmd
{
	char			**args;
	char			*infile;
	char			*outfile;
	int				append;
	int				heredoc_fd;
	struct s_cmd	*next;
}	t_cmd;
/* the shell operator, the commander of all */
typedef struct s_shell
{
	t_env		*env;
	t_cmd		*cmds;
	int			exit_status;
	char		*input;
}	t_shell;
#endif
