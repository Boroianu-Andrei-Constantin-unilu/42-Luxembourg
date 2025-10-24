/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/25 00:14:43 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	**allocate_grid(void)
{
	int	**g;
	int	i;
	int	j;

	g = malloc(4 * sizeof(int *));
	if (!g)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		g[i] = malloc(4 * sizeof(int));
		if (!g[i])
			return (NULL);
		j = 0;
		while (j < 4)
		{
			g[i][j] = 0;
			j++;
		}
		i++;
	}
	return (g);
}

void	print_grid(int **g)
{
	char	c;
	int		r;
	int		cidx;

	r = 0;
	while (r < 4)
	{
		cidx = 0;
		while (cidx < 4)
		{
			c = g[r][cidx] + '0';
			write(1, &c, 1);
			if (cidx < 3)
				write(1, " ", 1);
			cidx++;
		}
		write(1, "\n", 1);
		r++;
	}
}

void	free_all(int **g, int **c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(g[i]);
		free(c[i]);
		i++;
	}
	free(g);
	free(c);
}
