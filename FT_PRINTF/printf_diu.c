/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 19:43:24 by hyoon             #+#    #+#             */
/*   Updated: 2020/05/17 00:28:06 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf_d_minus(int itg, int len, t_param *par)
{
	int		i;
	int		count;

	count = 0;
	if (len > par->precision)
		i = len;
	else
		i = par->precision + 1;
	if ((par->dot && par->flags != '-')
			|| (par->flags != '-' && par->flags != '0'))
		count = ft_printf_count(' ', par->width - i);
	count += ft_putchar('-');
	if (!(par->dot) && par->flags == '0')
		count += ft_printf_count('0', par->width - i);
	count += ft_printf_count('0', i - len);
	if (itg == -2147483648)
	{
		count += ft_putnbr(214748364);
		count += ft_putchar('8');
	}
	else
		count += ft_putnbr(itg * -1);
	if (par->flags == '-')
		count += ft_printf_count(' ', par->width - count);
	return (count);
}

int		ft_printf_d(va_list *ap, t_param *par)
{
	int		itg;
	int		num;
	int		len;
	int		count;

	num = 0;
	itg = va_arg(*ap, int);
	len = ft_count_int(itg);
	if (itg == 0 && par->precision == 0)
		return (ft_printf_count(' ', par->width));
	else if (itg < 0)
		return (ft_printf_d_minus(itg, len, par));
	count = ft_printf_d_pre(&num, len, par);
	count += ft_printf_count('0', par->precision - len);
	count += ft_putnbr(itg);
	if (par->flags == '-' && par->precision > len)
		count += ft_printf_count(' ', num - par->precision);
	else if (par->flags == '-')
		count += ft_printf_count(' ', num - len);
	if (count != par->width)
		count += ft_printf_count(' ', par->width - count);
	return (count);
}

int		ft_putnbr_unsigned(unsigned int num)
{
	int		count;

	count = 0;
	if (num > 2147483647)
	{
		count = ft_putnbr_unsigned(num / 10);
		count += ft_putchar(num % 10 + '0');
	}
	else
		count = ft_putnbr(num);
	return (count);
}

int		ft_count_unsigned(unsigned int num)
{
	int		count;

	count = 0;
	while (num > 2147483647)
	{
		num = num / 10;
		count++;
	}
	count += ft_count_int((int)num);
	return (count);
}

int		ft_printf_u(va_list *ap, t_param *par)
{
	int					len;
	int					num;
	int					count;
	unsigned int		itg;

	itg = va_arg(*ap, unsigned int);
	if (itg == 0 && par->precision == 0)
		return (ft_printf_count(' ', par->width));
	len = ft_count_unsigned(itg);
	count = ft_printf_d_pre(&num, len, par);
	count += ft_printf_count('0', par->precision - len);
	count += ft_putnbr_unsigned(itg);
	if (par->flags == '-' && par->precision > len)
		count += ft_printf_count(' ', num - par->precision);
	else if (par->flags == '-')
		count += ft_printf_count(' ', num - len);
	if (count != par->width)
		count += ft_printf_count(' ', par->width - count);
	return (count);
}
