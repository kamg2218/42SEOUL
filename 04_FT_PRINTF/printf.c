/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 19:42:02 by hyoon             #+#    #+#             */
/*   Updated: 2020/05/20 18:32:29 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf_d_pre(int *num, int len, t_param *par)
{
	int		count;

	if (par->precision > par->width)
		*num = par->precision;
	else
		*num = par->width;
	count = 0;
	if (par->flags == '0' && par->precision > len
			&& par->dot == 0)
		count += ft_printf_count('0', *num - par->precision);
	else if (par->flags == '0' && par->dot == 0)
		count += ft_printf_count('0', *num - len);
	else if (par->flags != '-' && par->precision > len)
		count += ft_printf_count(' ', *num - par->precision);
	else if (par->flags != '-')
		count += ft_printf_count(' ', *num - len);
	return (count);
}

int		ft_printf_x(va_list *ap, t_param *par)
{
	int				len;
	int				h_len;
	int				count;
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	if (num == 0 && par->precision == 0)
		return (ft_printf_count(' ', par->width));
	h_len = ft_count_hexa((long long)num);
	count = ft_printf_d_pre(&len, h_len, par);
	count += ft_printf_count('0', par->precision - h_len);
	count += ft_putnbr_hexa((long long)num, 39);
	if (par->flags == '-' && par->precision > h_len)
		count += ft_printf_count(' ', len - par->precision);
	else if (par->flags == '-')
		count += ft_printf_count(' ', len - h_len);
	if (count != par->width)
		count += ft_printf_count(' ', par->width - count);
	return (count);
}

int		ft_printf_large_x(va_list *ap, t_param *par)
{
	int				len;
	int				h_len;
	int				count;
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	if (num == 0 && par->precision == 0)
		return (ft_printf_count(' ', par->width));
	h_len = ft_count_hexa((long long)num);
	count = ft_printf_d_pre(&len, h_len, par);
	count += ft_printf_count('0', par->precision - h_len);
	count += ft_putnbr_hexa((long long)num, 7);
	if (par->flags == '-' && par->precision > h_len)
		count += ft_printf_count(' ', len - par->precision);
	else if (par->flags == '-')
		count += ft_printf_count(' ', len - h_len);
	if (count != par->width)
		count += ft_printf_count(' ', par->width - count);
	return (count);
}

int		ft_percent(char c, va_list *ap, t_param *par)
{
	int		count;

	count = 0;
	if (c == '%')
		count = ft_putchar('%');
	else if (c == 'c')
		count = ft_printf_c(ap, par);
	else if (c == 's')
		count = ft_printf_s(ap, par);
	else if (c == 'p')
		count = ft_printf_p(ap, par);
	else if (c == 'd' || c == 'i')
		count = ft_printf_d(ap, par);
	else if (c == 'u')
		count = ft_printf_u(ap, par);
	else if (c == 'x')
		count = ft_printf_x(ap, par);
	else if (c == 'X')
		count = ft_printf_large_x(ap, par);
	else
		count = -1;
	return (count);
}

int		ft_printf(const char *str, ...)
{
	int			i;
	int			j;
	int			count;
	va_list		ap;
	t_param		par;

	va_start(ap, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ft_delparam(&par);
			i = ft_parcing(str, ++i, &ap, &par);
			if ((j = ft_percent(str[i], &ap, &par)) == -1)
				count += ft_printf_else(str, i);
			else
				count += j;
		}
		else
			count += ft_putchar(str[i]);
	}
	va_end(ap);
	return (count);
}
