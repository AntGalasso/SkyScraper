/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:14:37 by agalasso          #+#    #+#             */
/*   Updated: 2025/10/26 19:27:24 by agalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

void	print_error(void);
void	print_result(int grid[ROWS][COLS]);
void	free_grid(int grid[ROWS][COLS])
int		parse_input(char *str, int *numbers);
int		solve_rush01(int grid[ROWS][COLS], int *numbers, int pos);
int		is_valid_placement(int grid[ROWS][COLS], int row, int col, int val);
int		check_row_left(int grid[ROWS][COLS], int row, int expected);
int		check_row_right(int grid[ROWS][COLS], int row, int expected);
int		check_col_up(int grid[ROWS][COLS], int col, int expected);
int		check_col_down(int grid[ROWS][COLS], int col, int expected);
int		check_visibility(int grid[ROWS][COLS], int *numbers);

static void	init_grid(int grid[ROWS][COLS])
{
	int	row;
	int	col;

	row = 0;
	while (row < ROWS)
	{
		col = 0;
		while (col < COLS)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	numbers[16];
	int	grid[ROWS][COLS];

	if (argc != 2)
	{
		print_error();
		return (0);
	}
	if (!parse_input(argv[1], numbers))
	{
		print_error();
		return (0);
	}
	init_grid(grid);
	if (!solve_rush01(grid, numbers, 0))
	{
		print_error();
		return (0);
	}
	
	free_grid(grid);
	return (0);
}
