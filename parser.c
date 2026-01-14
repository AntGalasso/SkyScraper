/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:36:25 by agalasso          #+#    #+#             */
/*   Updated: 2025/10/26 19:00:00 by agalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

void	print_error(void);

void	free_grid(int grid[ROWS][COLS])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static int	add_number(char c, int *numbers, int *count)
{
	if (c >= '1' && c <= '4')
	{
		numbers[*count] = c - '0';
		(*count)++;
		if (*count > 16)
		{
			print_error();
			return (0);
		}
	}
	else if (c != ' ')
	{
		print_error();
		return (0);
	}
	return (1);
}

int	parse_input(char *str, int *numbers)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!add_number(str[i], numbers, &count))
			return (0);
		i++;
	}
	if (count != 16)
	{
		print_error();
		return (0);
	}
	return (1);
}
