#include <unistd.h>

void	rush(int x, int y)
{
	int a;
	int b;

	b = 1;
	while (b <= y)
	{
		a = 1;
		while (a <= x)
		{
			if (a == 1 && (b == 1 || b == y))
				ft_putchar('A');
			else if (a == x && (b == 1 || b == y))
				ft_putchar('C');
			else if (a == 1 || a == x || b == y || b == 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			a++;
		}
		write(1, "\n", 1);
		b++;
	}
}
