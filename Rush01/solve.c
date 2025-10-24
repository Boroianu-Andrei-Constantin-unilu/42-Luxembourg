/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/25 00:15:32 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_row(int **g, int **cl, int row);
int	check_col(int **g, int **cl, int col);
int	is_valid(int **g, int row, int col, int v);

int	solve(int **g, int **c, int pos)
{
	int	row;
	int	col;
	int	v;

	if (pos == 16)
		return (check_row(g, c, 3) && check_col(g, c, 3));
	row = pos / 4;
	col = pos % 4;
	v = 1;
	while (v <= 4)
	{
		if (is_valid(g, row, col, v))
		{
			g[row][col] = v;
			if (col == 3 && !check_row(g, c, row))
				g[row][col] = 0;
			else if (row == 3 && !check_col(g, c, col))
				g[row][col] = 0;
			else if (solve(g, c, pos + 1))
				return (1);
			g[row][col] = 0;
		}
		v++;
	}
	return (0);
}
