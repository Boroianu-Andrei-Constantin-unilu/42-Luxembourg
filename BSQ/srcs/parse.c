/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/11/05 17:25:10 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static int	ft_atoi_header(char *s, int *i)
{
	long	n;

	n = 0;
	*i = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		n = n * 10 + (s[*i] - '0');
		if (n > 2147483647)
			return (-1);
		(*i)++;
	}
	return ((int)n);
}

static int	parse_header(t_map *map, char *s)
{
	int	i;
	int	rows;

	i = 0;
	rows = ft_atoi_header(s, &i);
	if (rows <= 0 || ft_strlen(s) < i + 3)
		return (0);
	map->rows = rows;
	map->empty = s[i];
	map->obstacle = s[i + 1];
	map->full = s[i + 2];
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	return (1);
}

static char	**alloc_map_grid(int rows, int cols)
{
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * rows);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		grid[i] = malloc(cols + 1);
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
		grid[i][cols] = '\0';
		i++;
	}
	return (grid);
}

static int	fill_grid(t_map *map, char *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols && p[j] && p[j] != '\n')
		{
			map->grid[i][j] = p[j];
			j++;
		}
		if (j != map->cols)
			return (0);
		if (p[j] == '\n')
			p += j + 1;
		else
			p += j;
		i++;
	}
	return (1);
}

t_map	*parse_map(char *content)
{
	t_map	*map;
	char	*p;

	if (!content)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	if (!parse_header(map, content))
		return (free(map), NULL);
	p = content;
	while (*p && *p != '\n')
		p++;
	if (*p == '\n')
		p++;
	map->cols = 0;
	while (p[map->cols] && p[map->cols] != '\n')
		map->cols++;
	map->grid = alloc_map_grid(map->rows, map->cols);
	if (!map->grid || !fill_grid(map, p))
		return (free_map(map), NULL);
	return (map);
}
