/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/25 00:14:57 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *s)
{
	int	n;

	while (*s && *s == ' ')
		s++;
	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return (n);
}

static int	count_nums(char	*s)
{
	int	c;

	c = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s)
			c++;
		while (*s && *s != ' ')
			s++;
	}
	return (c);
}

static int	**allocate_matrix(void)
{
	int	**c;
	int	i;

	i = 0;
	c = malloc(4 * sizeof(int *));
	if (!c)
		return (NULL);
	while (i < 4)
	{
		c[i] = malloc(4 * sizeof(int));
		if (!c[i])
			return (NULL);
		i++;
	}
	return (c);
}

static int	fill_matrix(int **c, char *str)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		while (*str == ' ')
			str++;
		c[i / 4][i % 4] = ft_atoi(str);
		if (c[i / 4][i % 4] < 1 || c[i / 4][i % 4] > 4)
			return (0);
		while (*str && *str != ' ')
			str++;
		i++;
	}
	return (1);
}

int	**parse_input(char *str)
{
	int	**c;

	if (count_nums(str) != 16)
		return (NULL);
	c = allocate_matrix();
	if (!c)
		return (NULL);
	if (!fill_matrix(c, str))
		return (NULL);
	return (c);
}
