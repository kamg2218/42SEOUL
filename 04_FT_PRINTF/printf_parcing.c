/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parcing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 19:44:09 by hyoon             #+#    #+#             */
/*   Updated: 2020/05/20 18:32:52 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_delparam(t_param *par)
{
	par->flags = 0;
	par->width = 0;
	par->dot = 0;
	par->precision = 1;
	par->length = 0;
}

int		ft_parcing_w(const char *str, int i, va_list *ap, t_param *par)
{
	int		num;

	i--;
	num = 0;
	if (str[++i] == '*')
	{
		par->width = va_arg(*ap, int);
		if (par->width < 0)
		{
			par->width *= -1;
			par->flags = '-';
		}
		i++;
	}
	else
	{
		while (ft_isalnum(str[i]) == 4)
		{
			num = num * 10 + str[i] - '0';
			i++;
		}
		par->width = num;
	}
	return (i);
}

int		ft_parcing_p(const char *str, int i, va_list *ap, t_param *par)
{
	int		num;

	i--;
	num = 0;
	par->dot = 1;
	if (str[++i] == '*')
	{
		par->precision = va_arg(*ap, int);
		if (par->precision < 0)
		{
			par->dot = 0;
			par->precision = 1;
		}
		i++;
	}
	else
	{
		while (ft_isalnum(str[i]) == 4)
		{
			num = num * 10 + str[i] - '0';
			i++;
		}
		par->precision = num;
	}
	return (i);
}

int		ft_parcing(const char *str, int i, va_list *ap, t_param *par)
{
	i--;
	while (str[++i] == '+' || str[i] == ' ' || str[i] == '-'
			|| str[i] == '#' || str[i] == '0')
	{
		if (par->flags != '-')
			par->flags = str[i];
	}
	i--;
	i = ft_parcing_w(str, ++i, ap, par);
	if (str[i] == '.')
		i = ft_parcing_p(str, ++i, ap, par);
	while (str[i] == 'L' || str[i] == 'l')
	{
		par->length = str[i];
		i++;
	}
	return (i);
}
