/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminniti <tminniti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:31:33 by tminniti          #+#    #+#             */
/*   Updated: 2025/10/26 18:43:13 by tminniti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row(int grid[4][4], int row, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_col(int grid[4][4], int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}
