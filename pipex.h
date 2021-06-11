#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	*cmd1;
	char	*cmd2;

}	t_pipex;

int		error_argument(void);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*take_first_word(char *s);
int		first_word_lenght(char *s);
int		skip_quote(char *str, int *i);
int		ft_isalnum(int c);
int		fill_first_word(char *s, char **string, int *i, int *j);
char	**join_splits(char **splits, char *cmd);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalpha(int c);
void	redirection(t_pipex *pipex, char **env);
void	redirected_fork(t_pipex *pipex, char **env);
void	exec_path(char **splits, t_pipex *pipex, int num);
void	execute(t_pipex *pipex, char **env, int num);
void	execute_command(t_pipex *pipex, char **env, int num);
void	piping(t_pipex *pipex, char **env);
void	first_fork(t_pipex *pipex, int *fd, char **env);
void	first_fork_child(t_pipex *pipex, int *fd, char **env);
void	second_fork_child(t_pipex *pipex, int *fd, char **env);
void	free_str(char **str);

#endif