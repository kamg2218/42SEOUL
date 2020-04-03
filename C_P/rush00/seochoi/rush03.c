/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seochoi@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:51:13 by seochoi           #+#    #+#             */
/*   Updated: 2020/01/25 23:29:01 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

/*
 ** ABC
 ** B B
 ** ABC
 */
char	find_proper_chr(int x, int y, int a, int b)
{
	if (y == 0 || y == b - 1)
	{
		if (x == 0)
			return ('A');
		else if (x == a - 1)
			return ('C');
		else
			return ('B');
	}
	else
	{
		if (x == 0 || x == a - 1)
			return ('B');
		else
			return (' ');
	}
}

/*
 ** o-o
 ** | |
 ** o-o
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
		return '-';
	else if (row_count == 0 || column_count == x - 1 || row_count == y - 1 )
		return '|';
	else
		return ' ';
}

/*
**  Suppose input x, y as integer
*/
void		rush(int x, int y)
{
	int a;
	int b;

	b = 0;
	while (b < y)
	{
		a = 0;
		while (a < x)
		{
			/* ft_putchar(find_proper_chr(a, b, x, y)); */
			ft_putchar(get_char(a, b, x, y));
			a++;
		}
		write(1, "\n", 1);
		b++;
	}
}
