/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:11:49 by hyoon             #+#    #+#             */
/*   Updated: 2020/01/26 09:33:27 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** 041
 ** 785
 ** 263
 */
int	get_char(int row_count, int column_count, int x, int y)
{
	if (row_count == 0 && column_count == 0)
		return 0;
	else if (row_count == x - 1 && column_count == 0)
		return 1;
	else if (row_count == 0 && column_count == y - 1)
		return 2;
	else if (row_count == x - 1 && column_count == y - 1)
		return 3;
	else if (column_count == 0)
		return 4;
	else if (row_count == x - 1)
		return 5;
	else if (column_count == y - 1)
		return 6;
	else if (row_count == 0)
		return 7;
	else
		return 8;
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
	column_count = 0;
	while (column_count < y)
	{
		row_count = 0;
		while (row_count < x)
		{
			char_num = get_char(row_count, column_count, x, y);
			if (char_num == 0 || char_num == 3)
				ft_putchar('A');
			else if (char_num == 1 || char_num == 2)
				ft_putchar('C');
			else if (char_num >= 4 && char_num <= 7)
				ft_putchar('B');
			else
				ft_putchar(' ');
			row_count++;
		}
		write(1, "\n", 1);
		column_count++;
	}
}
