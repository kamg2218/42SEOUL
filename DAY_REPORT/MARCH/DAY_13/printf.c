#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	str;

	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, "8", 1);
    	return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		str = '0' + n % 10;
	}
    else
		str = '0' + n;
	write(fd, &str, 1);
}

int   ft_percent(char c, va_list *ap)
{
    if (c == 'd')
        ft_putnbr_fd(va_arg(*ap, int), 1);
    return (4);
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
        {
            count = ft_percent(s[++num], &ap);
            if (count == 4)
                va_arg(ap, int);
        }
        else
        {
            write(1, &s[num], 1);
            va_arg(ap, int);
        }
        num++;
    }
    return (0);
}

int main(){
    int a;

    ft_printf("%d", 12);
    return (0);
}