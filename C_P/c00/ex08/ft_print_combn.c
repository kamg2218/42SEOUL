/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:44:44 by hyoon             #+#    #+#             */
/*   Updated: 2020/01/27 22:23:02 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_nbr(int nbr, int n)
{
	int		c;
	int		i;

	i = 0;
	if (nbr > 9)
	{
		ft_nbr(nbr / 10, n - 1);
		c = '0' + nbr % 10;
	}
	else if (n != 1)
	{
		write(1, "0", 1);
		c = '0' + nbr;
	}
	else
		c = '0' + nbr;
	write(1, &c, 1);
}

int		check(int a, int ln, int n)
{
	if (a % 10 == ln)
	{
		if (a > 9 && check(a / 10, ln - 1, n) == 1)
			return (1);
		else if (10 - ln == n)
			return (1);
		else
			return (0);
	}
	return (0);
}

int		chtonbr(char *a, int n)
{
	int		i;
	int		j;
	int		nbr;
	int		count;

	nbr = 0;
	i = 1;
	while (i < n + 1)
	{
		j = 0;
		count = 1;
		while (j < n - i)
		{
			count = count * 10;
			j++;
		}
		nbr += count * (a[i - 1] - 48);
		i++;
	}
	return (nbr);
}

int		add_num(int nbr, int n, int i)
{
	char	a[10];

	if (nbr % 10 == 9)
	{
		while (++i < n)
		{
			a[n - i] = (nbr % 10) + '0';
			nbr /= 10;
		}
		a[0] = nbr + '0';
		i = 0;
		while (++i)
		{
			if (a[n - i] - '0' != 10 - i)
			{
				a[n - i] += 1;
				i = n - i;
				while (++i < n)
					a[i] = a[i - 1] + 1;
				return (chtonbr(a, n));
			}
		}
	}
	return (nbr += 1);
}

void	ft_print_combn(int n)
{
	int		nbr;
	int		i;
	char	a[10];

	i = 0;
	a[0] = '0';
	while (++i < n)
		a[i] = a[i - 1] + 1;
	nbr = chtonbr(a, n);
	nbr--;
	while (1)
	{
		nbr = add_num(nbr, n, 0);
		ft_nbr(nbr, n);
		if (nbr % 10 == 9 && check(nbr, 9, n) == 1)
			break ;
		write(1, ", ", 2);
	}
}
