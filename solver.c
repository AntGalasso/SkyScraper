/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:36:31 by agalasso          #+#    #+#             */
/*   Updated: 2025/10/26 19:05:00 by agalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

void	print_error(void);
void	print_result(int grid[ROWS][COLS]);
int		is_valid_placement(int grid[ROWS][COLS], int row, int col, int val);
int		check_visibility(int grid[ROWS][COLS], int *numbers);
int		try_number(int grid[ROWS][COLS], int *numbers, int pos);
int		solve_rush01(int grid[ROWS][COLS], int *numbers, int pos);
int		is_valid_placement(int grid[ROWS][COLS], int row, int col, int val);

int	solve_rush01(int grid[ROWS][COLS], int *numbers, int pos)
{
	if (pos == 16)
	{
		if (check_visibility(grid, numbers))
		{
			print_result(grid);
			return (1);
		}
		return (0);
	}
	return (try_number(grid, numbers, pos));
}

int	try_number(int grid[ROWS][COLS], int *numbers, int pos)
{
	int	row;
	int	col;
	int	num;

	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_valid_placement(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_rush01(grid, numbers, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	is_valid_placement(int grid[ROWS][COLS], int row, int col, int val)
{
	int	i;

	i = 0;
	while (i < COLS)
	{
		if (grid[row][i] == val)
			return (0);
		i++;
	}
	i = 0;
	while (i < ROWS)
	{
		if (grid[i][col] == val)
			return (0);
		i++;
	}
	return (1);
}
