/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/25 00:14:19 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	count_visible(int	*line)
{
	int	max;
	int	vis;
	int	i;

	max = 0;
	vis = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			vis++;
		}
		i++;
	}
	return (vis);
}

int	is_valid(int	**g, int row, int col, int v)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g[row][i] == v || g[i][col] == v)
			return (0);
		i++;
	}
	return (1);
}

int	check_row(int **g, int **cl, int r)
{
	int	row[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		row[i] = g[r][i];
		if (!row[i])
			return (1);
		i++;
	}
	if (count_visible(row) != cl[2][r])
		return (0);
	i = 0;
	while (i < 4)
	{
		row[i] = g[r][3 - i];
		i++;
	}
	return (count_visible(row) == cl[3][r]);
}

int	check_col(int **g, int **cl, int c)
{
	int	col[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		col[i] = g[i][c];
		if (!col[i])
			return (1);
		i++;
	}
	if (count_visible(col) != cl[0][c])
		return (0);
	i = 0;
	while (i < 4)
	{
		col[i] = g[3 - i][c];
		i++;
	}
	return (count_visible(col) == cl[1][c]);
}
