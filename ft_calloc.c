#include "pipex.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned long	*str;
	size_t			j;
	unsigned char	*p;

	j = n;
	str = s;
	p = s;
	i = 0;
	if (n == 0)
		return ;
	n = n / 8;
	while (i < n)
	{
		(str)[i] = 0;
		i++;
	}
	i = n * 8;
	n = j % 8;
	j = 0;
	while (j < n)
	{
		p[i++] = 0;
		j++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}
