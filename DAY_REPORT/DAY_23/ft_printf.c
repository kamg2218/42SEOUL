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

int    ft_percent_check(const char *s, va_list *ap)
{
    int     i;
    int     j;
    int     num;

    //flags
    i = 0;
    if (s[++i] == '#' || s[i] == '-' || s[i] == '+' 
        || s[i] == '0' || s[i] == ' ')
        param.flags = s[i];
    else
        i--;
    //width
    num = 0;
    while (ft_isalnum(s[++i]) == 4)
        num = num * 10 + s[i] - '0';
    param.width = num;
    //precision
    if (s[i] == '.')
    {
        num = 0;
        while (ft_isalnum(s[++i]) == 4)
            num = num * 10 + s[i] - '0';
        param.precision = num;
    }
    //size
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
    //type
    param.type = s[i];

    return (0);
}

int     ft_percent(const char *s, va_list *ap)
{
    int     num;
    char    c;
    char    *n_str;

    num = ft_percent_check(s, ap);
    printf("param.flags = %c\n", param.flags);
    printf("param.width = %d\n", param.width);
    printf("param.precision = %d\n", param.precision);
    printf("param.size = %s\n", param.size);
    printf("param.type = %c\n", param.type);
/*
    c = *(s + num + 1);
    if (c == 'd')
        ft_putnbr_int(va_arg(*ap, int), n_str);
    else if (c == 'f')
        ft_putnbr_flt(va_arg(*ap, double), n_str);
    else if (c == 'c')
        ft_putchar(va_arg(*ap, int));
    else if (c == 's')
        ft_putstr(va_arg(*ap, char *));
    if (n_str)
        free(n_str);
*/
    return (num + 1);
}

int     ft_printf(const char *s, ...)
{
    int         num;
    va_list     ap;

    va_start(ap, s);
    num = 0;
    while (s[num] != '\0')
    {
        if (s[num] == '%')
            num += ft_percent(&s[num], &ap);
        else
            write(1, &s[num], 1);
        num++;
    }
    free(param.size);
    return (0);
}

int main()
{
    printf("%5.10d\n", 123);
    ft_printf("%#5.10hd\n", 123);
    return (0);
}