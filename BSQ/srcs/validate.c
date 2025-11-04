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

static int	is_valid_char(t_map *map, char c)
{
	if (c == map->empty || c == map->obstacle)
		return (1);
	return (0);
}

int	validate_map(t_map *map)
{
	int	i;
	int	j;

	if (!map || map->rows <= 0 || map->cols <= 0)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (!is_valid_char(map, map->grid[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
