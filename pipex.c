#include "pipex.h"

t_pipex	*get_arguments(char **argv)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (NULL);
	if (pipex == NULL)
		return (NULL);
	pipex->infile = open(argv[1], S_IRUSR);
	if (pipex->infile < 0)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
	}
	pipex->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (pipex->outfile < 0)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
	}
	pipex->cmd1 = ft_strdup(argv[2]);
	pipex->cmd2 = ft_strdup(argv[3]);
	return (pipex);
}

void	print_arguments(t_pipex *pipex)
{
	printf("infile==> %d\n", pipex->infile);
	printf("outfile==> %d\n", pipex->outfile);
	printf("cmd1==> %s\n", pipex->cmd1);
	printf("cmd2==> %s\n", pipex->cmd2);
}

void	free_pipex(t_pipex *pipex)
{
	free(pipex->cmd1);
	free(pipex->cmd2);
	free(pipex);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(int argc, char **argv, char **env)
{
	char	*str;
	t_pipex	*pipex;
	int		i;

	str = NULL;
	i = 0;
	pipex = NULL;
	if (argc != 5)
		return (error_argument());
	pipex = get_arguments(argv);
	if (pipex == NULL)
		return (1);
	piping(pipex, env);
	free_pipex(pipex);
	return (0);
}
