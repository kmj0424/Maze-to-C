#include "so_long.h"

static int	c_check(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_temp_j(char **temp, int j)
{
	while (j > 0)
		free(temp[--j]);
	free(temp);
	return (NULL);
}

void	ft_ft_while(char **temp, int *j, char const **s, char c)
{
	int	k;

	k = 0;
	while (**s != c && **s)
	{
		temp[*j][k] = **s;
		k++;
		(*s)++;
	}
	temp[*j][k] = '\0';
	(*j)++;
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	temp = (char **)calloc(sizeof(char *), (c_check(s, c) + 1));
	if (temp == NULL)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		i = 0;
		while (s[i] != c && s[i] != '\0')
			i++;
		temp[j] = (char *)calloc(sizeof(char), (i + 1));
		if (temp[j] == NULL)
			return (ft_temp_j(temp, j));
		ft_ft_while(temp, &j, &s, c);
	}
	return (temp);
}