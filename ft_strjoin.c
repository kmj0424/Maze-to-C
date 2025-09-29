#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*pt;
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return s2;
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
	while (*s2)
	{
		pt[i] = *s2;
		i++;
		s2++;
	}
	pt[i] = '\0';
	return (pt);
}