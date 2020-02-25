char	*ft_strrchr(char *str, int c)
{
	unsigned int    i;
	unsigned int    result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == c)
			result = i;
		i++;
	}
	if (result != 0 || str[0] == c)
		return (str + result);
	else
		return (0);
}
