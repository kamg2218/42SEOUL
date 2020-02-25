int		ft_memcmp(const void *ptr1, const void *ptr2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*((char *)ptr1 + i) != *((char *)ptr2 + i))
			return (*((char *)ptr1 + i) - *((char *)ptr2 + i));
		i++;
	}
	return (0);
}
