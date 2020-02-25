void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*((char *)s + i) == c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
