#include "pipex.h"

void	execute(t_pipex *pipex, char **env, int num)
{
	char	**splits;
	int		i;
	char	**str;

	i = 0;
	while (env[i])
	{
		str = ft_split(env[i], '=');
		if (str == NULL)
			break ;
		if (ft_strcmp(str[0], "PATH") == 0)
			break ;
		i++;
	}
	splits = ft_split(str[1], ':');
	free_str(str);
	if (num == 1)
		splits = join_splits(splits, pipex->cmd1);
	else
		splits = join_splits(splits, pipex->cmd2);
	exec_path(splits, pipex, num);
	free_str(splits);
}

void	exec_path(char **splits, t_pipex *pipex, int num)
{
	int		i;
	char	**cmd;
	int		check;

	i = 0;
	check = 0;
	if (num == 1)
		cmd = ft_split(pipex->cmd1, ' ');
	else
		cmd = ft_split(pipex->cmd2, ' ');
	while (splits[i])
	{
		execve(splits[i], cmd, NULL);
		i++;
	}
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		write(2, "command not found\n", 18);
		free_str(cmd);
		exit(EXIT_FAILURE);
	}
}

char	**join_splits(char **splits, char *cmd)
{
	int		i;
	char	*str;
	char	*str_free;

	i = 0;
	str = take_first_word(cmd);
	while (splits[i])
	{
		str_free = splits[i];
		splits[i] = ft_strjoin(splits[i], "/");
		free(str_free);
		str_free = splits[i];
		splits[i] = ft_strjoin(splits[i], str);
		free(str_free);
		i++;
	}
	free(str);
	return (splits);
}

int	error_argument(void)
{
	write(1, "error : arguments number\n", 25);
	return (1);
}
