#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*pt;

	size = ft_strlen(s);
	pt = malloc(sizeof(char) * (size + 1));
	if (pt == NULL)
		return (NULL);
	size = 0;
	while (size < ft_strlen(s))
	{
		pt[size] = s[size];
		size++;
	}
	pt[size] = '\0';
	return (pt);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*ss;

	i = 0;
	if (!s)
		return (NULL);
	ss = (unsigned char *)s;
	while (ss[i])
	{
		if (ss[i] == (unsigned char)c)
			return ((char *)(ss + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(ss + i));
	return (NULL);
}

char	*ft_ft_strjoin(char *s1, char *s2)
{
	int		k;
	char	*pt;
	size_t	i;

	i = 0;
	k = 0;
	pt = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (pt == NULL)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (*s1)
	{
		pt[i] = *s1;
		i++;
		s1++;
	}
	while (s2[k])
	{
		pt[i] = s2[k];
		i++;
		k++;
	}
	pt[i] = '\0';
	return (pt);
}

char	*ft_substr(char **s, unsigned int start, size_t len)
{
	char	*pt;
	size_t	i;

	i = 0;
	if (*s == NULL || ft_strlen(*s) < start)
		return (NULL);
	if (ft_strlen(*s) - start < len)
		len = ft_strlen(*s) - start;
	pt = (char *)malloc(len + 1);
	if (pt == NULL)
		return (NULL);
	if (ft_strlen(*s) < len)
		return (pt);
	i = 0;
	while (i < ft_strlen(*s) && i < len)
	{
		pt[i] = (*s)[start];
		i++;
		start++;
	}
	free(*s);
	pt[i] = '\0';
	return (pt);
}