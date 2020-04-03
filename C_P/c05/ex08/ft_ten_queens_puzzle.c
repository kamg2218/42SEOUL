/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:13:05 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/06 20:24:07 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	set_zero(int *queens)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		queens[i] = 0;
		i++;
	}
}

void	ft_print_queens(int *queens)
{
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		j = queens[i] + '0';
		write(1, &j, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_check(int *queens, int l)
{
	int		i;

	i = 0;
	if (queens[l] > 9)
		return (0);
	while (i < l)
	{
		if (queens[i] == queens[l])
			return (0);
		else if (queens[i] + (l - i) == queens[l])
			return (0);
		else if (queens[i] - (l - i) == queens[l])
			return (0);
		i++;
	}
	return (1);
}

void	ft_queens_puzzle(int *queens, int i)
{
	while (i < 10)
	{
		if (queens[0] == 9 && queens[1] == 8)
			return ;
		if (ft_check(queens, i))
			i++;
		else if (queens[i] < 9)
			queens[i] += 1;
		else
		{
			queens[i - 1] += 1;
			queens[i] = 0;
			i--;
		}
	}
	ft_print_queens(queens);
}

int		ft_ten_queens_puzzle(void)
{
	int		i;
	int		count;
	int		queens[10];

	set_zero(queens);
	i = 0;
	count = 0;
	while (1)
	{
		ft_queens_puzzle(queens, i);
		if (queens[0] == 9 && queens[1] == 8)
			return (count);
		count += 1;
		i = 9;
		queens[9] += 1;
	}
	return (count);
}
