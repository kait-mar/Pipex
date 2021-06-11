#include "pipex.h"

void	piping(t_pipex *pipex, char **env)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	first_fork(pipex, fd, env);
	pid = fork();
	if (pid == -1)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		second_fork_child(pipex, fd, env);
	else
	{
		if (waitpid(pid, NULL, WUNTRACED) == -1)
			write(2, strerror(errno), ft_strlen(strerror(errno)));
	}
	close(fd[1]);
	close(fd[0]);
	close(pipex->outfile);
}

void	first_fork_child(t_pipex *pipex, int *fd, char **env)
{
	close(fd[0]);
	if (dup2(pipex->infile, 0) < 0)
	{
		exit(EXIT_FAILURE);
	}
	close(pipex->infile);
	if (dup2(fd[1], 1) < 0)
	{
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	execute(pipex, env, 1);
	exit(EXIT_FAILURE);
}

void	first_fork(t_pipex *pipex, int *fd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		first_fork_child(pipex, fd, env);
	else
	{
		if (waitpid(pid, NULL, WUNTRACED) == -1)
			write(2, strerror(errno), ft_strlen(strerror(errno)));
	}
	close(fd[1]);
	close(pipex->infile);
}

void	second_fork_child(t_pipex *pipex, int *fd, char **env)
{
	close(fd[1]);
	if (dup2(fd[0], 0) < 0)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	if (dup2(pipex->outfile, 1) < 0)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		exit(EXIT_FAILURE);
	}
	close(pipex->outfile);
	execute(pipex, env, 2);
}
