#ifndef     FT_PRINTF_H
# define    FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

//ft_printf_char
void    ft_putchar(char c);
void    ft_putstr(char *s);
void    ft_putspace(int front, int back, int quo);
int     ft_putpos(char *n_str, int  *front);
double  ft_round(double nbr, int back);

//ft_printf_nbr
void	ft_putnbr(int n);
void    ft_putnbr_int(int n, char *n_str);
void    ft_putnbr_flt(double flt, char *n_str);
int     ft_flt_back_check(int quo, double rem, int back);

//ft_printf
int		ft_isalnum(int c);
int     ft_printf(const char *s, ...);
int     ft_percent(const char *s, va_list *ap);
char    *ft_percent_check(const char *s);

#endif