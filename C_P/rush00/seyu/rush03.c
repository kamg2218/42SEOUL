/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seochoi@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:26:16 by seyu              #+#    #+#             */
/*   Updated: 2020/01/25 22:48:14 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_putchar.c"

char	find_proper_chr(int x_size, int y_size, int x, int y)
{
	if (y == 0 || y == y_size - 1)
	{
		if (x == 0)
			return ('A');
		else if (x == x_size - 1)
			return ('C');
		else
			return ('B');
	}
	else
	{
		if (x == 0 || x == x_size - 1)
			return ('B');
		else
			return (' ');
	}
}

void	rush(int x_size, int y_size)
{
	int		x;
	int		y;

	y = 0;
	while (y < y_size)
	{
		x = 0;
		while (x < x_size)
		{
			ft_putchar(find_proper_chr(x_size, y_size, x, y));
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
