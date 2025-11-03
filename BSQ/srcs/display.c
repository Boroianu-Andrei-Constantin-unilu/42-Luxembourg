#include "bsq.h"

void	display_map(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			write(1, &map->grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
