void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		if (*((char *)src + i) == c)
			return ((char *)dest + i + 1);
		else if (*((char *)src + i) == '\0')
			break;
		i++;
	}
	return (0);
}
