/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/21 17:48:31 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	**init_dp(t_map *map)
{
	int	**dp;
	int	i;

	dp = malloc(sizeof(int *) * map->rows);
	if (!dp)
		return (NULL);
	i = 0;
	while (i < map->rows)
	{
		dp[i] = malloc(sizeof(int) * map->cols);
		if (!dp[i])
		{
			while (--i >= 0)
				free(dp[i]);
			free(dp);
			return (NULL);
		}
		i++;
	}
	return (dp);
}

static void	update_square(t_square *sq, int val, int r, int c)
{
	sq->size = val;
	sq->row = r - val + 1;
	sq->col = c - val + 1;
}

static void	dp_loop(t_map *map, int **dp, t_square *sq)
{
	int	r;
	int	c;
	int	minv;

	r = 0;
	while (r < map->rows)
	{
		c = 0;
		while (c < map->cols)
		{
			if (map->grid[r][c] == map->obstacle)
				dp[r][c] = 0;
			else if (r == 0 || c == 0)
				dp[r][c] = 1;
			else
			{
				minv = ft_min(dp[r - 1][c], ft_min(dp[r][c - 1], dp[r - 1][c - 1]));
				dp[r][c] = 1 + minv;
			}
			if (dp[r][c] > sq->size)
				update_square(sq, dp[r][c], r, c);
			c++;
		}
		r++;
	}
}

t_square	find_biggest_square(t_map *map)
{
	t_square	sq;
	int			**dp;
	int			i;

	sq.row = 0;
	sq.col = 0;
	sq.size = 0;
	dp = init_dp(map);
	if (!dp)
		return (sq);
	dp_loop(map, dp, &sq);
	i = 0;
	while (i < map->rows)
		free(dp[i++]);
	free(dp);
	return (sq);
}

void	fill_square(t_map *map, t_square sq)
{
	int	i;
	int	j;

	i = 0;
	while (i < sq.size)
	{
		j = 0;
		while (j < sq.size)
		{
			map->grid[sq.row + i][sq.col + j] = map->full;
			j++;
		}
		i++;
	}
}
