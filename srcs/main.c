#include "../includes/minishell.h"
//step 1: list all arguments in the cmd in a linked list tp avoid memory leaks
/* char	*find_path(char *string)
{
	char	*new_string;

	new_string = ft_strjoin(string, "/");
	if (!new_string)
		return (NULL);
	return (new_string);
} */

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	/* char	*path;
	char	**path_list;
	char	*full_path;
	int	i;

	path = getenv("PATH"); //getenv returns a pointer
	path_list = ft_split(path, ':');
	if (!path_list)
		return (-1);
	i = 0;
	while (path_list[i] != NULL)
	{
		full_path = malloc(ft_strlen(path_list[i]) + ft_strlen(argv[1]) + 2);
		if (!full_path)
		{
			while (i >= 0)
				free(path_list[i--]);
			free(path_list);
			return (-1);
		}
		full_path = ft_strjoin(find_path(path_list[i]), argv[1]);
		if (!full_path)
		{
			while (i >= 0)
				free(path_list[i--]);
			free(path_list);
			return (-1);
		}
		if (access(full_path, X_OK) == 0)
		{
			int new_id = fork();
			while (i >= 0)
				free(path_list[i--]);
			free(path_list);
			if (!new_id)
				break ;
			if (new_id == 0)
			{
				execve(full_path, argv, NULL);
				waitpid(new_id, NULL, 0);
			}
		}
		i++;
	}
	free(full_path); */
	return (0);
}
