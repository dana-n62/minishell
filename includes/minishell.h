/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:13:39 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/05/13 18:35:15 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>
/*# include <stdio.h>
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
	char			**args; /*the list of each word in the input*/
	char			*infile; /*where open should read from*/
	char			*outfile; /*where write should write to*/
	int				append; /*should the data be written over or added to EOF*/
	int				heredoc_fd; /*the fd for redirecting using pipes*/
	struct s_cmd	*next;
}	t_cmd;
/* the shell operator, the commander of all */
typedef struct s_shell
{
	t_env		*env;
	t_cmd		*cmds;
	int			exit_status; /*to assess the function ended falsely or with errors*/
	char		*input; /*the input raw line (as is)*/
}	t_shell;
/*defining the token struct, its type as enum*/
/*enum assigns a name for an integer value  starting from 0 incrementing until the end of list*/
typedef enum s_token_type
{
	WORD, /*any string even the enviroment var (0)*/
	PIPE, /* | (1)*/
	REDIR_IN, /* < (2)*/
	REDIR_OUT, /* > (3)*/
	REDIR_APPEND, /* >> (4)*/
	HEREDOC, /* << (5)*/
}	t_token_type;
typedef struct s_token
{
	char			*value;
	t_token_type	type;
	char			quote;
	struct s_token	*next;
}	t_token;

t_token	*ft_new_token(char *value, t_token_type type, char quote);
void	ft_token_addback(t_token **head, t_token *new);
t_token	*ft_get_operator(char *input, int *i);
int		ft_get_redir(t_token **temp, char *op);
t_token	*ft_lexer(char *input);
void	free_tokens(t_token **token);
t_env	*env_list(char **envp);
t_env	*ft_new_env(char *envp);
void	free_env(t_env **env);
void	setup_signals(void);
t_cmd	*ft_new_cmd(void);
void	ft_cmd_addback(t_cmd **head, t_cmd *new);
void	ft_free_cmd(t_cmd **head);
int		count_words(t_token *temp);
int		ft_handle_word(t_token **temp, t_cmd **current);
int		ft_handle_redir(t_token **temp, t_cmd **current);
t_cmd	*ft_parser(t_token *tokens);
#endif
