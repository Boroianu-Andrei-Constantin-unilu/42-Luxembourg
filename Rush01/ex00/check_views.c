/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_views.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminniti <tminniti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:39:46 by tminniti          #+#    #+#             */
/*   Updated: 2025/10/26 18:39:56 by tminniti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible(int *line);

int	check_col_up(int grid[4][4], int col, int val)
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[i][col];
		i++;
	}
	return (count_visible(line) == val);
}

int	check_col_down(int grid[4][4], int col, int val)
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[3 - i][col];
		i++;
	}
	return (count_visible(line) == val);
}

int	check_row_left(int grid[4][4], int row, int val);
int	check_row_right(int grid[4][4], int row, int val);

int	check_views(int grid[4][4], int *v)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_col_up(grid, i, v[i])
			|| !check_col_down(grid, i, v[4 + i])
			|| !check_row_left(grid, i, v[8 + i])
			|| !check_row_right(grid, i, v[12 + i]))
			return (0);
		i++;
	}
	return (1);
}
