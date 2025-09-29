#include "get_next_line.h"

size_t	ft_buflen(char *s)
{
	char	*new_line;

	new_line = ft_strchr(s, '\n');
	return (new_line - s + 1);
}

char	*ft_while(char **buf, char **temp, char **ret, int read_size)
{
	char	*tp;

	(*buf)[read_size] = '\0';
	if (ft_strchr(*buf, '\n'))
	{
		*temp = ft_strdup((*buf) + ft_buflen(*buf));
		(*buf) = ft_substr(buf, 0, ft_buflen(*buf));
	}
	tp = ft_ft_strjoin(*ret, *buf);
	free(*ret);
	return (tp);
}

void	*ft_calloc(size_t size)
{
	size_t		c;
	char		*res;

	c = 0;
	res = malloc(size + 1);
	while (c < size + 1)
		res[c++] = 0;
	return (res);
}

void	find_new_line(char **ret, char **temp, char **buf, int fd)
{
	int		read_size;

	read_size = 1;
	if (ft_strchr(*ret, '\n'))
	{
		*temp = ft_strdup(*ret + ft_buflen(*ret));
		*ret = ft_substr(ret, 0, ft_buflen(*ret));
	}
	else
	{
		while (!(ft_strchr(*ret, '\n')) && read_size)
		{
			read_size = read(fd, *buf, BUFFER_SIZE);
			if (read_size <= 0)
			{
				if (!(*ret) || ft_strlen(*ret) == 0)
				{
					free(*ret);
					*ret = NULL;
				}
				return ;
			}
			*ret = ft_while(buf, temp, ret, read_size);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*temp = NULL;
	char		*buf;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE);
	if (!temp)
		ret = ft_strdup("");
	else
	{
		ret = ft_strdup(temp);
		free(temp);
		temp = NULL;
	}
	find_new_line(&ret, &temp, &buf, fd);
	free(buf);
	return (ret);
}
