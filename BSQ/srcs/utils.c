#include "bsq.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
