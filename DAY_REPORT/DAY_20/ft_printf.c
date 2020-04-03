#include "ft_printf.h"

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
char    *ft_percent_check(const char *s)
{
    int     i;
    char    *n_str;

    i = 0;
    while (ft_isalnum(*(s + i)) == 4 || *(s + i) == '.')
        i++;
    n_str = (char *)malloc(sizeof(char) * (i + 1));
    if (n_str == NULL)
        return (0);
    i = 0;
    while (ft_isalnum(*(s + i)) == 4 || *(s + i) == '.')
    {
        n_str[i] = *(s + i);
        i++;
    }
    n_str[i] = 0;
    return (n_str);
}
int     ft_percent(const char *s, va_list *ap)
{
    int     num;
    char    c;
    char    *n_str;

    num = 0;
    if (ft_isalnum(*(s + 1)) != 2)
    {
        n_str = ft_percent_check(s + 1);
        while (n_str[num])
            num++;
    }
    c = *(s + num + 1);
    if (c == 'd')
        ft_putnbr_int(va_arg(*ap, int), n_str);
    else if (c == 'u')
        ft_putnbr_unsigned_int(va_arg(*ap, int), n_str);
    else if (c == 'f')
        ft_putnbr_flt(va_arg(*ap, double), n_str);
    else if (c == 'c')
        ft_putchar(va_arg(*ap, int));
    else if (c == 's')
        ft_putstr(va_arg(*ap, char *));
    if (n_str)
        free(n_str);
    return (num + 1);
}
int     ft_printf(const char *s, ...)
{
    int         num;
    char        *str;
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
    str = va_arg(ap, char *);
    if (str)
        ft_printf(str, ap);
    return (0);
}

int main(){
    int a;
/*
    ft_printf("%d", 12);
    printf("\n");
    ft_printf("%1.2f", 12.1);
*/
    char s[10] = "ab\n\'\"\t";

    printf("!%u!\n", 2147483648);
    ft_printf("%u\n", 2147483648);

    return (0);
}