/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/25 00:20:47 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		**parse_input(char *str);
int		solve(int **grid, int **clues, int pos);
void	print_grid(int **grid);
void	free_all(int **grid, int **clues);
int		**allocate_grid(void);

int	main(int ac, char **av)
{
	int	**clues;
	int	**grid;

	if (ac != 2)
		return (write(1, "Error\n", 6), 1);
	clues = parse_input(av[1]);
	if (!clues)
		return (write(1, "Error\n", 6), 1);
	grid = allocate_grid();
	if (!solve(grid, clues, 0))
		write(1, "Error\n", 6);
	else
		print_grid(grid);
	free_all(grid, clues);
	return (0);
}
