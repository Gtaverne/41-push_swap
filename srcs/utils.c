#include "../includes/pushswap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

long int	ft_atoi(const char *nptr, t_a *a)
{
	long long int		i;
	long long int		r;
	long long int		s;

	i = 0;
	r = 0;
	s = 1;
	if (nptr[i] == '-')
	{
		s = -1;
		i++;
	}
	while (nptr[i] != '\0')
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			r = r * 10 + nptr[i] - '0';
		else
			break ;
		i++;
	}
	if (r > 2147483647 + (1 - s) / 2)
		ft_cleanexit(a, "Error, value out of int range\n", 2);
	return (s * r);
}

char	*ft_strdup(char *s)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

void	ft_freesplit(char **str)
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
