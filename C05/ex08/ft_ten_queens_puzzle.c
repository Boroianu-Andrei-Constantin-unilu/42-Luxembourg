#include <unistd.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

int	ft_abs(int n) {
	if (n < 0) {
		return (-n);
    }
	return n;
}

void ft_print_solution(int *board) {
	int	i = 0;
	while (i < 10) {
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	ft_is_valid(int *board, int col, int row) {
	int	i = 0;
	while (i < col) {
		if (board[i] == row || ft_abs(board[i] - row) == ft_abs(i - col)) {
			return 0;
        }
		i++;
	}
	return 1;
}

void ft_solve(int *board, int col, int *count) {
	int	row = 0;

	if (col == 10) {
		ft_print_solution(board);
		(*count)++;
		return ;
	}

	while (row < 10) {
		if (ft_is_valid(board, col, row)) {
			board[col] = row;
			ft_solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void) {
	int	board[10];
	int	count = 0;

	ft_solve(board, 0, &count);
	return (count);
}