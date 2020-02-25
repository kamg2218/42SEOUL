void	*ft_memcpy(void *destination, const void *source, unsigned int num)
{
	unsigned int	i;
	char		c;

	i = 0;
	while (i < num)
	{
		*((char *)destination + i) = *((char *)source + i);
		if (*((char *)source + i) == '\0')
			break;
		i++;
	}
	return (destination);
}
