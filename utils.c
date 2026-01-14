/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:36:41 by agalasso          #+#    #+#             */
/*   Updated: 2025/10/26 18:55:42 by agalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_result(int grid[ROWS][COLS])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < ROWS)
	{
		col = 0;
		while (col < COLS)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < COLS - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	is_valid_char(char c)
{
	if (c >= '1' && c <= '4')
		return (1);
	return (0);
}

int	ft_atoi(char *str, int *i)
{
	int	num;

	num = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = num * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (num);
}
