/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 19:27:44 by hyoon             #+#    #+#             */
/*   Updated: 2020/05/20 01:59:05 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>

typedef struct	s_param
{
	char		flags;
	int			width;
	int			dot;
	int			precision;
	char		length;
	char		type;
}				t_param;

int				ft_putchar(char c);
int				ft_putstr(char *str, t_param *par);
int				ft_putnbr(int num);
int				ft_putnbr_hexa(long long num, int asc);
int				ft_putnbr_hexa_limit(int asc);

int				ft_isalnum(int c);
int				ft_count_int(int num);
int				ft_printf_count(char c, int num);
int				ft_count_str(char *str);
int				ft_count_hexa(long long hex);

int				ft_parcing_w(const char *str, int i, va_list *ap, t_param *par);
int				ft_parcing_p(const char *str, int i, va_list *ap, t_param *par);
int				ft_parcing(const char *str, int i, va_list *ap, t_param *par);
void			ft_delparam(t_param *par);

int				ft_printf_c(va_list *ap, t_param *par);
int				ft_printf_s(va_list *ap, t_param *par);
int				ft_printf_p(va_list *ap, t_param *par);
int				ft_putstr_w(wchar_t *str, t_param *par);
int				ft_printf_else(const char *str, int i);

int				ft_count_unsigned(unsigned int num);
int				ft_putnbr_unsigned(unsigned int num);
int				ft_printf_d(va_list *ap, t_param *par);
int				ft_printf_u(va_list *ap, t_param *par);
int				ft_printf_d_minus(int itg, int len, t_param *par);

int				ft_printf(const char *str, ...);
int				ft_printf_x(va_list *ap, t_param *par);
int				ft_printf_large_x(va_list *ap, t_param *par);
int				ft_percent(char c, va_list *ap, t_param *par);
int				ft_printf_d_pre(int *num, int len, t_param *par);

#endif
