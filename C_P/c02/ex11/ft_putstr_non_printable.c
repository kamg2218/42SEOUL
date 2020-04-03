/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:11:35 by hyoon             #+#    #+#             */
/*   Updated: 2020/01/31 14:18:00 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hex(unsigned char s)
{
	unsigned int	a[2];
	unsigned int	i;

	a[0] = s / 16;
	a[1] = s % 16;
	i = 0;
	while (i < 2)
	{
		if (a[i] < 10)
			a[i] += 48;
		else
			a[i] += 87;
		write(1, &a[i], 1);
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			hex((unsigned char)str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
