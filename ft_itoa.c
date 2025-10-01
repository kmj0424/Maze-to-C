#include "so_long.h"

static int	ft_count(long long n)
{
	long long	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_while(long long real,
				char *temp, long long i, long long sign)
{
	temp[i] = '\0';
	while (--i > 0)
	{
		temp[i] = (real % 10) + '0';
		real = real / 10;
	}
	if (sign == 1)
		temp[i] = '-';
	else if (sign == 0)
		temp[i] = real + '0';
	return (temp);
}

static char	*ft_zero(void)
{
	char	*temp;

	temp = (char *)malloc(2);
	if (temp == NULL)
		return (NULL);
	temp[0] = '0';
	temp[1] = '\0';
	return (temp);
}

char	*ft_itoa(int n)
{
	char		*temp;
	long long	i;
	long long	sign;
	long long	real;

	real = (long long)n;
	sign = 0;
	if (real < 0)
	{
		real *= -1;
		sign += 1;
	}
	else if (real == 0)
		return (ft_zero());
	i = ft_count(real) + sign;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		return (NULL);
	ft_while(real, temp, i, sign);
	return (temp);
}