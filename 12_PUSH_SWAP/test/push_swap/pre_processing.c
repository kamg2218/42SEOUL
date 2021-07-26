#include "push_swap.h"

int	check_string(char *c)
{
	int	i;

	i = 0;
	if (c[0] == '+' || c[0] == '-')
		i++;
	while (c[i])
	{
		if (ft_isalnum(c[i]) != 4)
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

void	arrange_str(char *str)
{
	int		num;

	num = 0;
	if (str[0] == '+')
		ft_strlcpy(str, str + 1, ft_strlen(str));
	else if (str[0] == '-')
		num++;
	while (str[num] == '0' && ft_strlen(str + num) != 1)
		ft_strlcpy(str + num, str + num + 1, ft_strlen(str + num));
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
	arrange_str(str);
	num = ft_atoi(str);
	if (num == 0 && str[0] == '-')
		ft_strlcpy(str, str + 1, ft_strlen(str));
	if (ft_strlen(str) != numlen(num) || check_dup(*tmp, num))
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

t_stack	*pre_processing(int argc, char *argv[], t_param *p)
{
	t_stack	*tmp;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	tmp = parsing(argc, argv);
	if (tmp == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	p->cmd = (int *)ft_calloc(4, 100);
	if (p->cmd == NULL)
	{
		write(2, "Error\n", 6);
		clear(&tmp);
		return (NULL);
	}
	p->cap = 100;
	p->size = 0;
	return (tmp);
}
