/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_views_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminniti <tminniti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:39:22 by tminniti          #+#    #+#             */
/*   Updated: 2025/10/26 18:39:31 by tminniti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_visible(int *line)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_row_left(int grid[4][4], int row, int val)
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][i];
		i++;
	}
	return (count_visible(line) == val);
}

int	check_row_right(int grid[4][4], int row, int val)
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][3 - i];
		i++;
	}
	return (count_visible(line) == val);
}
