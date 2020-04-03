#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
void    ft_putstr(char *s)
{
    int     i;

    i = 0;
    while (s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
}
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
int     ft_putpos(char *n_str, int  *front)
{
    int     i;
    int     j;
    int     back;

    i = -1;
    *front = 0;
    while (n_str[++i] != '.')
        *front = *front * 10 + n_str[i] - '0';
    j = 0;
    back = 0;
    while (n_str[i + ++j])
        back = back * 10 + n_str[i + j] - '0';
    return (back);
}
void    ft_putspace(int front, int back, int quo)
{
    int   i;

    i = 0;
    while (quo)
    {
        quo /= 10;
        i++;
    }
    while (++i + back < front)
        ft_putchar(' ');
}
void	ft_putnbr(int n)
{
	char	str;

	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
        ft_putchar('8');
    	return ;
	}
	else if (n < 0)
	{
        ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		str = '0' + n % 10;
	}
    else
		str = '0' + n;
    ft_putchar(str);
}
void    ft_putnbr_int(int n, char *n_str)
{
    int     front;

    ft_putpos(n_str, &front);
    ft_putspace(front, 0, n);
    ft_putnbr(n);
}
void    ft_putnbr_flt(float flt, char *n_str)
{
    int     i;
    int     back;
    int     front;
    int     quo;
    float   rem;

    quo = (int)(flt);
    rem = flt - (double)(quo);
    back = ft_putpos(n_str, &front);
    ft_putspace(front, back, quo);
    ft_putnbr(quo);
    ft_putchar('.');
    i = -1;
    while (++i < back - 1)
    {
      ft_putchar((int)(rem * 10) + '0');
      rem = (rem * 10) - (int)(rem * 10);
    }
    if ((int)(rem * 100) % 10 >= 5 && i < 6)
        ft_putchar((int)(rem * 10) + '1');
    else
        ft_putchar((int)(rem * 10) + '0');
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
    int     front;
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