#include "ft_printf.h"

//1
void    ft_putchar(char c)
{
    write(1, &c, 1);
}
//2
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
//3
int     ft_putpos(char *n_str, int  *front)
{
    int     i;
    int     j;
    int     back;

    *front = 0;
    if (!n_str)
        return (-1);
    i = -1;
    while (n_str[++i] != '.' && n_str[i])
        *front = *front * 10 + n_str[i] - '0';
    j = 0;
    back = 0;
    while (n_str[i + ++j])
        back = back * 10 + n_str[i + j] - '0';
    if (!back && n_str[i] != '.')
        return (-1);
    return (back);
}
//4
void    ft_putspace(int front, int back, int quo)
{
    int   i;

    i = 0;
    while (quo)
    {
        quo /= 10;
        i++;
    }
    if (!back)
        i--;
    else if (back == -1)
        back = 6;
    while (++i + back < front)
        ft_putchar(' ');
}
