/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_visibility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:20:00 by agalasso          #+#    #+#             */
/*   Updated: 2025/10/26 19:26:39 by agalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

int	check_row_left(int grid[ROWS][COLS], int row, int expected);
int	check_row_right(int grid[ROWS][COLS], int row, int expected);
int	check_col_up(int grid[ROWS][COLS], int col, int expected);
int	check_col_down(int grid[ROWS][COLS], int col, int expected);

int	check_visibility(int grid[ROWS][COLS], int *numbers)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_col_up(grid, i, numbers[i]))
			return (0);
		if (!check_col_down(grid, i, numbers[i + 4]))
			return (0);
		if (!check_row_left(grid, i, numbers[i + 8]))
			return (0);
		if (!check_row_right(grid, i, numbers[i + 12]))
			return (0);
		i++;
	}
	return (1);
}

int	check_row_left(int grid[ROWS][COLS], int row, int expected)
{
	int	max_height;
	int	visible;
	int	i;

	max_height = 0;
	visible = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[row][i] > max_height)
		{
			max_height = grid[row][i];
			visible++;
		}
		i++;
	}
	return (visible == expected);
}

int	check_row_right(int grid[ROWS][COLS], int row, int expected)
{
	int	max_height;
	int	visible;
	int	i;

	max_height = 0;
	visible = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[row][i] > max_height)
		{
			max_height = grid[row][i];
			visible++;
		}
		i--;
	}
	return (visible == expected);
}
