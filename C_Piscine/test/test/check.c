int		ft_is_space(char *str)
{
	if (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f'
			|| *str == '\r')
		return (1);
	else
		return (0);
}
int		ft_is_non_printable(char *str)
{
	if (*str < 32 || *str > 126)
		return (1);
	else
		return (0);
}
int		ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_validate_key(char *str)
{
	int		i;
	int 	count;
	int		colon_index;

	i = 0;
	count = 0;
	colon_index = 0;
	while (*(str + i) != '\n')
	{
		if (!ft_is_numeric(*(str)))
			return (0);
		if (ft_is_numeric(*(str + i)))
		{
			count++;
			i++;
		}
		if (ft_is_space(str + i))
			i++;
		if (*(str + i) == ':')
			colon_index = i;
		i++;
	}
	if (colon_index == 0)
		return (0);
	else
		return (colon_index);
}

int		ft_validate_value(char *str)
{
	int i;
	int j;
	int from;
	int colon_index;

	colon_index = ft_validate_key(str);
	if (colon_index == 0)
		return (0);
	i = colon_index + 1;
	while (*(str + i) != '\n')
	{
		if (ft_is_non_printable(str + i))
			return (0);
		else
			i++;
	}
	return (1);
}

int		ft_validate_dict(char *str)
{
	if (!ft_validate_key(str))
		return (0);
	if (!ft_validate_value(str))
		return (0);
	return (1);
}
