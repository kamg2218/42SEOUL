/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 19:44:47 by hyoon             #+#    #+#             */
/*   Updated: 2020/05/16 23:14:58 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf_count(char c, int num)
{
	int		i;

	if (num <= 0)
		return (0);
	i = -1;
	while (++i < num)
		write(1, &c, 1);
	return (num);
}

int		ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (4);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else
		return (0);
}

int		ft_count_str(char *str)
{
	int		i;

	if (!str)
		return (6);
	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int		ft_count_int(int num)
{
	int		i;

	i = 0;
	if (num <= 0)
	{
		num *= -1;
		i++;
	}
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int		ft_count_hexa(long long hex)
{
	int		i;

	i = 0;
	if (hex == 0)
		return (1);
	while (hex)
	{
		hex = hex / 16;
		i++;
	}
	return (i);
}
