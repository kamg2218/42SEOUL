#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

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
void	ft_putnbr(int n)
{
	char	str;

	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		write(1, "8", 1);
    	return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		str = '0' + n % 10;
	}
    else
		str = '0' + n;
	write(1, &str, 1);
}
void    ft_putnbr_flt(double flt)
{

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
        ft_putnbr(va_arg(*ap, int));
    else if (c == 'f')
        ft_putnbr_flt(va_arg(*ap, double));
    free(n_str);
    return (num + 1);
}

int     ft_printf(const char *s, ...)
{
    int         count;
    int         num;
    char        *cha;
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

    ft_printf(&s[0]);
    printf("!\n");

    printf("!%s!", s);
    return (0);
}