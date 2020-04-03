/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mingukim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:00:48 by mingukim          #+#    #+#             */
/*   Updated: 2020/02/02 22:37:17 by mingukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		g_col_up[4];
int		g_col_down[4];
int		g_row_left[4];
int		g_row_right[4];
int		g_finish = 0;

void	putint(int n)
{
	char	c;

	c = n + 48;
	write(1, &c, 1);
}

void	print_map(int map[4][4])
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			putint(map[row][col]);
			if (col == 3)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			col++;
		}
		row++;
	}
	write(1, "\n", 1);
}
/*
**g_finish++;
*/

int		check_see(int map[4][4], int row, int col)
{
	int see_up;
	int see_down;
	int see_left;
	int see_right;
	int see_height;
	int i;
	int num_count;

	i = 1;
	see_up = 1;
	see_height = map[0][col];
	while (i < 4)
	{
		if (see_height <= map[i][col])
		{
			see_up++;
			see_height = map[i][col];
		}
		i++;
	}
	i = 2;
	see_down = 1;
	see_height = map[3][col];
	while (i >= 0)
	{
		if (see_height <= map[i][col])
		{
			see_down++;
			see_height = map[i][col];
		}
		i--;
	}
	i = 1;
	see_left = 1;
	see_height = map[row][0];
	while (i < 4)
	{
		if (see_height <= map[row][i])
		{
			see_left++;
			see_height = map[row][i];
		}
		i++;
	}
	i = 2;
	see_right = 1;
	see_height = map[row][3];
	while (i >= 0)
	{
		if (see_height <= map[row][i])
		{
			see_right++;
			see_height = map[row][i];
		}
		i--;
	}
	if (map[row][col] <= 2)
	{
		if ((see_up != g_col_up[col] || see_down != g_col_down[col]) ||
				(see_left != g_row_left[row] || see_right != g_row_right[row]))
			return (0);
	}
	else
	{
		if ((see_up < g_col_up[col] || see_down < g_col_down[col]) ||
				(see_left < g_row_left[row] || see_right < g_row_right[row]))
			return (0);
	}
	i = 0;
	num_count = 0;
	while (i < 4)
	{
		if (map[i][col] == map[row][col])
			num_count++;
		i++;
	}
	if (num_count > 1)
		return (0);
	print_map(map);
	return (1);
}

void	put_in_box(int (*map)[4], int height, int row, int col)
{
	if (g_finish > 0)
		return ;
	while (map[row][col] > 0)
	{
		if (col < 3)
			col++;
		else
			return ;
	}
	map[row][col] = height;
	if (check_see(map, row, col))
	{
		if (row == 4)
		{
			if (height == 1)
				print_map(map);
			else
				put_in_box(map, height - 1, 0, 0);
		}
		else
			put_in_box(map, height, row + 1, 0);
	}
	map[row][col] = 0;
	if (col < 3)
		put_in_box(map, height, row, col + 1);
	return ;
}

int		main(int argc, char *argv[])
{
	int i;
	int map[4][4];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (i < 32)
	{
		if (i < 8)
			g_col_up[i / 2] = argv[1][i] - 48;
		else if (i < 16)
			g_col_down[(i - 8) / 2] = argv[1][i] - 48;
		else if (i < 24)
			g_row_left[(i - 16) / 2] = argv[1][i] - 48;
		else
			g_row_right[(i - 24) / 2] = argv[1][i] - 48;
		i += 2;
	}
	i = 0;
	while (i < 16)
	{
		map[i / 4][i % 4] = 0;
		i++;
	}
	put_in_box(map, 4, 0, 0);
}
