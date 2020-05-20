/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_csp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 19:43:37 by hyoon             #+#    #+#             */
/*   Updated: 2020/05/20 18:26:15 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf_c(va_list *ap, t_param *par)
{
	int		count;

	count = 0;
	if (par->flags != '-')
		count += ft_printf_count(' ', par->width - 1);
	if (par->length == 'l')
		count += ft_putchar((wchar_t)va_arg(*ap, wint_t));
	else
		count += ft_putchar((unsigned char)va_arg(*ap, int));
	if (par->flags == '-')
		count += ft_printf_count(' ', par->width - 1);
	return (count);
}

int		ft_printf_s(va_list *ap, t_param *par)
{
	int		num;
	int		len;
	int		count;
	char	*str;

	count = 0;
	str = va_arg(*ap, char*);
	num = ft_count_str(str);
	if (num > par->precision && par->dot)
		len = par->precision;
	else
		len = num;
	if (par->dot == 1 && par->precision == 0)
		return (ft_printf_count(' ', par->width));
	else if (par->flags != '-')
		count += ft_printf_count(' ', par->width - len);
	if (par->length == 'l')
		count += ft_putstr_w((wchar_t*)str, par);
	else
		count += ft_putstr(str, par);
	if (par->flags == '-')
		count += ft_printf_count(' ', par->width - len);
	return (count);
}

int		ft_printf_p(va_list *ap, t_param *par)
{
	int			len;
	int			num;
	int			count;
	long long	addr;

	addr = (long long)va_arg(*ap, void*);
	count = 2;
	len = (!addr && !(par->precision)) ? 0 : ft_count_hexa(addr);
	count += ft_printf_d_pre(&num, len + 2, par);
	write(1, "0x", 2);
	if (!addr && (par->precision))
		count += ft_printf_count('0', par->precision);
	else
		count += ft_printf_count('0', par->precision - len);
	count += addr == 0 ? 0 : ft_putnbr_hexa(addr, 39);
	if (par->flags == '-' && par->precision > len)
		count += ft_printf_count(' ', num - par->precision);
	else if (par->flags == '-')
		count += ft_printf_count(' ', num - len - 2);
	if (count != par->width)
		count += ft_printf_count(' ', par->width - count);
	return (count);
}

int		ft_putstr_w(wchar_t *str, t_param *par)
{
	int		i;
	int		len;
	int		count;

	i = -1;
	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	if (par->dot == 0)
		count = len;
	else
		count = par->precision;
	while (++i < count && str[i])
		write(1, &str[i], 1);
	return (i);
}

int		ft_printf_else(const char *str, int i)
{
	int		num;
	int		count;

	num = i;
	count = 0;
	while (str[num] != '%')
		num--;
	while (num <= i)
	{
		count += ft_putchar(str[num]);
		num++;
	}
	return (count);
}
