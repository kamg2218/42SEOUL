unsigned int	ft_strlen(const char *string)
{
	unsigned int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}
