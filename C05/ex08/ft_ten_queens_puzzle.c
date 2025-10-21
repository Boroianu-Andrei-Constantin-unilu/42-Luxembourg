/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboroia <anboroia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:05 by anboroia          #+#    #+#             */
/*   Updated: 2025/10/21 19:01:58 by anboroia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_print_solution(int *board)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		write(1, board[i] + '0', 1);
		i++;
	}
	write(1, '\n', 1);
}

int	ft_is_valid(int *board, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || ft_abs(board[i] - row) == ft_abs(i - col))
			return (0);
		i++;
	}
	return (1);
}

void	ft_solve(int *board, int col, int *count)
{
	int	row;

	if (col == 10)
	{
		ft_print_solution(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (ft_is_valid(board, col, row))
		{
			board[col] = row;
			ft_solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	ft_solve(board, 0, &count);
	return (count);
}
