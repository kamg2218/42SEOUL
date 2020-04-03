/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:36:03 by hyoon             #+#    #+#             */
/*   Updated: 2020/01/29 12:52:51 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    add_num(int *a, int *b)
{
	if (*b == 57)
	{
		*b = 48;
		*a += 1;
	}
 	else
		*b += 1;
}

void	ft_print_comb2(void)
{
	int a;
	int b;
	int c;
	int d;

	a = 48;
	b = 48;
	while (a != 57 || b != 57)
	{
		c = a;
		d = b;
		while (c != 57 || d != 57)
		{
			add_num(&c, &d);
			write(1, &a, 1);
			write(1, &b, 1);
			write(1, " ", 1);
			write(1, &c, 1);
			write(1, &d, 1);
			if (a == 57 && b == 56 && c == 57 && d == 57)
				break ;
			write(1, ", ", 2);
		}
		add_num(&a, &b);
	}
}
