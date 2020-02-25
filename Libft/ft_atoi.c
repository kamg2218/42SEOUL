int		ft_atoi(const char *str)
{
	int		i;
	int		minus;
	int		result;

	i = 0;
	minus = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		else
			minus = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * minus);
}
