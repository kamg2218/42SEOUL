/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 19:44:34 by hyoon             #+#    #+#             */
/*   Updated: 2020/05/16 23:12:07 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *str, t_param *par)
{
	int		i;
	int		len;
	int		count;

	if (!str)
	{
		count = ft_putstr("(null)", par);
		return (count);
	}
	len = ft_count_str(str);
	if (par->dot == 0)
		count = len;
	else
		count = par->precision;
	i = -1;
	while (++i < count && str[i])
		write(1, str + i, 1);
	return (i);
}

int		ft_putnbr(int num)
{
	int		count;
	char	ch;

	count = 0;
	if (num == -2147483648)
	{
		count += ft_putnbr(num / 10);
		write(1, "8", 1);
		return (count + 1);
	}
	else if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num *= -1;
	}
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
		ch = num % 10 + '0';
	}
	else
		ch = num + '0';
	ft_putchar(ch);
	return (count + 1);
}

int		ft_putnbr_hexa_limit(int asc)
{
	int			i;
	char		c;
	long long	num;

	num = -140725072341848;
	i = ft_putnbr_hexa(num / 16, asc);
	c = num % 16 + '0';
	if (c > 9 + '0')
		c += asc;
	write(1, &c, 1);
	return (i + 1);
}

int		ft_putnbr_hexa(long long num, int asc)
{
	int		i;
	char	c;

	i = 0;
	if (num == -140725072341848)
		return (ft_putnbr_hexa_limit(asc));
	else if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
		i++;
	}
	if (num > 15)
	{
		i += ft_putnbr_hexa(num / 16, asc);
		c = num % 16 + '0';
	}
	else
		c = num + '0';
	if (c > 9 + '0')
		c += asc;
	write(1, &c, 1);
	return (i + 1);
}
