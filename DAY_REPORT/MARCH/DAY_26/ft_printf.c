#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_parameters
{
    char    flags;
    int     width;
    int     precision;
    char    *size;
    char    type;
}t_parameters;

t_parameters  param;

//1
int     ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
//2
int     ft_putstr(char *s)
{
    int     i;
    int     j;

    if (param.precision >= 0)
        j = param.precision;
    else
    {
        j = 0;
        while (s[j])
            j++; 
    }
    i = -1;
    while (s[++i] && i < j)
        ft_putchar(s[i]);
    return (i);
}
//3
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
//4
int     ft_param_size(const char *s, int i)
{
    int     j;
    int     num;

    num = 0;
    while (s[i + num] == 'l' || s[i + num] == 'h')
        num++;
    param.size = (char *)malloc(sizeof(char) * (num + 1));
    if (param.size == NULL)
        return (-1);
    j = -1;
    while (++j < num)
    {
        param.size[j] = s[i];
        i++;
    }
    param.size[j] = 0;
    return (i);
}
//5
int     ft_flags_check(char c)
{
    if (c == '#' || c == '-' 
        || c == '+' || c == '0')
        return (1);
    else if (c == ' ' || c == '\v' 
        || c == '\f' || c == '\r' || c == '\t')
        return (1);
    else
        return (0);
}
//6
int     ft_percent_check(const char *s, va_list *ap)
{
    int     i;
    int     num;

    i = 0;
    if (ft_flags_check(s[++i]))
        param.flags = s[i];
    else
        i--;
    num = -1;
    if (ft_isalnum(s[i + 1]) == 4)
        num = 0;
    while (ft_isalnum(s[++i]) == 4)
        num = num * 10 + s[i] - '0';
    if (s[i] == '*')
        num = va_arg(*ap, int);
    param.width = num;
    num = -1;
    if (s[i] == '.')
    {
        num = 0;
        while (ft_isalnum(s[++i]) == 4)
            num = num * 10 + s[i] - '0';
        if (s[i] == '*')
            num = va_arg(*ap, int);
    }
    param.precision = num;
    i = ft_param_size(s, i);    
    param.type = s[i];
    return (i);
}
//7
void	ft_putnbr(unsigned int n)
{
	char	str;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		str = '0' + n % 10;
	}
    else
		str = '0' + n;
    ft_putchar(str);
}
//8
int    ft_count_int(int n)
{
    int     i;

    i = 0;
    if (n == -2147483648)
        return (11);
    else if (n < 0)
    {
        n = -n;
        i++;
    }
    while (n)
    {
        n = n / 10;
        i++;
    }
    return (i);
}
//9
int    ft_putnbr_int(int n)
{
    int   i;

    i = ft_count_int(n);
    if (n < 0)
	{
        ft_putchar('-');
		ft_putnbr(-n);
	}
    else
        ft_putnbr(n);
    return (ft_count_int(n));
}
//10
int     ft_non_flags(int n, int num)
{
    int     i;
    int     j;

    i = ft_count_int(n);
    if (param.width > num)
    {
        j = -1;
        while (++j < param.width - num)
            ft_putchar(' ');
        j--;
        while (++j < num - i + 1)
            ft_putchar('0');
        ft_putnbr_int(n);
    }
    else
    {
        j = -1;
        while (++j < num - i)
            ft_putchar('0');
        ft_putnbr_int(n);
    }
    return (j + i);
}
int     ft_minus_flags(int n, int num)
{
    int     i;
    int     j;
    int     minus;

    if (n >= 0)
        minus = 1;
    else
        minus = 0;
    i = ft_count_int(n);
    if (param.width > num + minus)
    {
        j = -1;
        while (++j < param.width - num - minus)
            ft_putchar(' ');
        j--;
        if (minus)
        {
            ft_putchar(' ');
            j++;
        }
        while (++j < num - i + 1)
            ft_putchar('0');
        ft_putnbr_int(n);
    }
    else
    {
        if (minus)
            ft_putchar(' ');
        j = -1;
        while (++j < num - i)
            ft_putchar('0');
        ft_putnbr_int(n);
    }
    return (j + i);
}
int     ft_checknbr_int(int n)
{
    int     i;
    int     num;

    i = ft_count_int(n);
    if (i < param.precision)
        num = param.precision;
    else
        num = i;
    if (param.flags == '-')
    {

    }
    else if (param.flags == '0')
    {

    }
    else
        return(ft_non_flags(n, num));
}
//11
int     ft_percent(const char *s, va_list *ap)
{
    int     num;

    num = ft_percent_check(s, ap);
    printf("param.flags = %c\n", param.flags);
    printf("param.width = %d\n", param.width);
    printf("param.precision = %d\n", param.precision);
    printf("param.size = %s\n", param.size);
    printf("param.type = %c\n", param.type);

    if (param.type == 'c')
        num = ft_putchar(va_arg(*ap, int));
    else if (param.type == 's')
        ft_putstr(va_arg(*ap, char *));
    else if (param.type == 'd')
        num = ft_checknbr_int(va_arg(*ap, int));
/*
    else if (param.type == 'f')
        ft_putnbr_flt(va_arg(*ap, double));
*/
    return (num);
}
//12
int     ft_param_count(void)
{
    int   i;
    int   num;

    num = 0;
    if (param.flags)
        num++;
    i = param.width;
    while (i > 0)
    {
      i = i / 10;
      num++;
    }
    i = param.precision;
    if (i > -1)
      num++;
    while (i > 0)
    {
      i = i / 10;
      num++;
    }
    i = -1;
    while (param.size[++i])
        num++;
    return (num + 1);
}
//13
void    ft_clear_param(void)
{
    param.flags = 0;
    param.width = -1;
    param.precision = -1;
    free(param.size);
    param.type = 0;
}
//14
int     ft_printf(const char *s, ...)
{
    int         num;
    int         count;
    va_list     ap;

    va_start(ap, s);
    num = 0;
    count = 0;
    while (s[num] != '\0')
    {
        if (s[num] == '%')
        {
            count += ft_percent(&s[num], &ap);
            num += ft_param_count();
            ft_clear_param();
        }  
        else
        {
            write(1, &s[num], 1);
            count++;
        }
        num++;
    }
    return (count);
}

int main(void)
{
//    printf("%d\n%6.5d\n", 123, 1234);
//    ft_printf("%d\n%6.5d\n", 123, 1234);

    printf("%c\n", 'a');
    ft_printf("%c\n", 'a');
    printf("%.2s\n", "abc");
    ft_printf("%.2s\n", "abc");
    return (0);
}