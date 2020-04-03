#include "ft_printf.h"

//1
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
//2
void    ft_putnbr_int(int n, char *n_str)
{
    int     front;

    ft_putpos(n_str, &front);
    ft_putspace(front, 0, n);
    ft_putnbr(n);
}
//3
int     ft_flt_back_check(int quo, double rem, int back)
{
    int     i;

    if (!back)
    {
        if ((int)(rem * 10) % 10 >= 5)
            ft_putnbr(quo + 1);
        else
            ft_putnbr(quo);
    }
    else if (back == -1)
    {
        ft_putnbr(quo);
        ft_putchar('.');
        i = -1;
        while (++i < 6)
        {
            ft_putchar((int)(rem * 10) + '0');
            rem = (rem * 10) - (int)(rem * 10);
        }
    }
    else
        return (0);
    return (1);
}
//4
void    ft_putnbr_flt(double dou, char *n_str)
{
    int     i;
    int     back;
    int     front;
    double   rem;

    back = ft_putpos(n_str, &front);
    dou = ft_round(dou, back);
    rem = dou - (double)((int)(dou)) + 0.000000001;
    if (!((int)(dou)))
        ft_putspace(front, back, 1);
    else
        ft_putspace(front, back, (int)(dou));
    if (!ft_flt_back_check((int)(dou), rem, back))
    {
        ft_putnbr((int)(dou));
        ft_putchar('.');
        i = -1;
        while (++i < back)
        {
            ft_putchar((int)(rem * 10) + '0');
            rem = (rem * 10) - (int)(rem * 10);
        }
    }
}
//5