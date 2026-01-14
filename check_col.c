/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:26:52 by agalasso          #+#    #+#             */
/*   Updated: 2025/10/26 19:27:01 by agalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:21:00 by agalasso          #+#    #+#             */
/*   Updated: 2025/10/26 19:21:00 by agalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

int	check_col_up(int grid[ROWS][COLS], int col, int expected)
{
	int	max_height;
	int	visible;
	int	i;

	max_height = 0;
	visible = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			visible++;
		}
		i++;
	}
	return (visible == expected);
}

int	check_col_down(int grid[ROWS][COLS], int col, int expected)
{
	int	max_height;
	int	visible;
	int	i;

	max_height = 0;
	visible = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			visible++;
		}
		i--;
	}
	return (visible == expected);
}
