#include "pipex.h"

char	*take_first_word(char *s)
{
	char	*string;
	int		i;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	string = malloc(first_word_lenght(s) + 1);
	if (!string)
		return (0);
	i = 0;
	while (s[i])
	{
		if (fill_first_word(s, &string, &i, &j))
			continue ;
		else if (ft_isalnum(s[i]) || s[i] == '/' || s[i] == '\'')
			string[j++] = s[i++];
		else
			break ;
	}
	string[j] = '\0';
	return (string);
}

int	first_word_lenght(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i])
	{
		if (skip_quote(s, &i))
			continue ;
		else if (ft_isalnum(s[i]) || s[i] == '/' )
			i++;
		else
			break ;
	}
	return (i);
}

int	skip_quote(char *str, int *i)
{
	int	on;

	on = 0;
	if (str[*i] == '"')
	{
		*i += 1;
		while (str[*i] != '\0' && str[*i] != '"')
			*i += 1;
		if (str[*i] == '"')
			*i += 1;
		on = 1;
	}
	else if (str[*i] == '\'')
	{
		*i += 1;
		while (str[*i] != '\0' && str[*i] != '\'')
			*i += 1;
		if (str[*i] == '\'')
			*i += 1;
		on = 1;
	}
	return (on);
}

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) == 1 || ft_isalpha(c) == 1)
		return (1);
	return (0);
}

int	fill_first_word(char *s, char **string, int *i, int *j)
{
	int	on;

	on = 0;
	if (s[*i] == '\'')
	{
		(*string)[(*j)++] = s[(*i)++];
		while (s[*i] && s[*i] != '\'')
			(*string)[(*j)++] = s[(*i)++];
		if (s[*i] == '\'')
			(*string)[(*j)++] = s[(*i)++];
		on = 1;
	}
	else if (s[*i] == '"')
	{
		(*string)[(*j)++] = s[(*i)++];
		while (s[*i] && s[*i] != '"')
			(*string)[(*j)++] = s[(*i)++];
		if (s[*i] == '"')
			(*string)[(*j)++] = s[(*i)++];
		on = 1;
	}
	return (on);
}
