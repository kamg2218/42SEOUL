/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:11:49 by hyoon             #+#    #+#             */
/*   Updated: 2020/01/25 21:34:37 by sangpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar.c"

/*
 ** 041
 ** 785
 ** 263
 */
char	get_char(int row_count, int column_count, int x, int y)
{
	if (column_count == 0 && row_count == 0)
		return 'o';
	else if (column_count == x - 1 && row_count == 0)
		return 'o';
	else if (column_count == 0 && row_count == y - 1)
		return 'o';
	else if (column_count == x - 1 && row_count == y - 1)
		return 'o';
	else if(column_count == 0 || column_count == x - 1)
		return '|';
	else if (row_count == 0 || column_count == x - 1 || row_count == y - 1 )
		return '-';
	else
		return ' ';
}

/*
**  suppose input x and y as integer
*/

void	rush(int x, int y)
{
	int row_count;
	int column_count;
	int char_num;

	if (x <= 0 || y <= 0)
	{
		write(1, "WRONG INPUT!!", 13);
		return ;
	}
	row_count = 0;
	while (row_count < y)
	{
		column_count = 0;
		while (column_count < x)
		{
			ft_putchar(get_char(row_count, column_count, x, y));
			column_count++;
		}
		write(1, "\n", 1);
		row_count++;
	}
}
