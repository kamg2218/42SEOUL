void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src < dest)
			*((char *)dest + (n - i - 1)) = *((char *)src + (n - i - 1));
		else
			*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}
