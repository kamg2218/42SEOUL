#include "checker.h"

int	check_string(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] != '-' && c[i] != '+' && ft_isalnum(c[i]) != 4)
			return (1);
		i++;
	}
	return (0);
}

size_t	numlen(int num)
{
	size_t	i;
	long	n;

	i = 0;
	n = (long)num;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	add_stack(t_stack **tmp, char *str)
{
	int	num;

	if (check_string(str))
	{
		if (*tmp != NULL)
			clear(tmp);
		return (1);
	}
	num = ft_atoi(str);
	if (ft_strlen(str) != numlen(num))
	{
		if (*tmp != NULL)
			clear(tmp);
		return (1);
	}
	push_back(tmp, num);
	return (0);
}

t_stack	*parsing(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**c;
	t_stack	*tmp;

	i = 1;
	tmp = NULL;
	while (i < argc)
	{
		c = ft_split(argv[i], ' ');
		j = 0;
		while (c[j])
		{
			if (add_stack(&tmp, c[j]))
				return (NULL);
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

t_stack	*pre_processing(int argc, char *argv[])
{
	t_stack	*tmp;

	if (argc < 2)
	{
		printf("Input Error\n");
		return (NULL);
	}
	tmp = parsing(argc, argv);
	if (tmp == NULL)
	{
		printf("Input Error\n");
		return (NULL);
	}
	return (tmp);
}
