#include "push_swap.h"

int				check_string(char* c)
{
	int		i;

	i = 0;
	while (c[i])
	{
		if (c[i] != '-' && c[i] != '+' && ft_isalnum(c[i]) != 4)
			return (1);
		i++;
	}
	return (0);
}

int				numlen(int num)
{
	int		i;
	long	n;

	i = 0;
	n = (long)num;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

t_stack*		pre_processing(int argc, char* argv[])
{
	int			i;
	int			j;
	int			num;
	char**		c;
	t_stack*	tmp;

	i = 1;
	while (i < argc)
	{
		c = ft_split(argv[i], ' ');
		j = 0;
		while (c[j])
		{
			num = ft_atoi(c[j]);
			printf("num = %d\n", num);
			if (check_string(c[j]) || ft_strlen(c[j]) != numlen(num))
			{
				clear(&tmp);
				return (NULL);
			}
			push_back(&tmp, num);
			j++;
		}
		j = 0;
		while (c[j])
			free(c[j++]);
		free(c);
		i++;
	}
	return (tmp);
}
