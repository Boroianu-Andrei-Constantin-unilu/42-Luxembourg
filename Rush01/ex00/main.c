/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminniti <tminniti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:31:39 by tminniti          #+#    #+#             */
/*   Updated: 2025/10/26 18:36:22 by tminniti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		parse_input(char *str, int *views);
void	print_grid(int grid[4][4]);
int		solve(int grid[4][4], int *views, int pos);

static void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

static int	print_error(int *views)
{
	write(1, "Error\n", 6);
	if (views)
		free(views);
	return (0);
}

int	main(int argc, char **argv)
{
	int	*views;
	int	grid[4][4];

	if (argc != 2)
		return (print_error(NULL));
	views = malloc(sizeof(int) * 16);
	if (!views || !parse_input(argv[1], views))
		return (print_error(views));
	init_grid(grid);
	if (solve(grid, views, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	free(views);
	return (0);
}
