unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (src[j])
		j++;
	if (n == 0)
		return (j);
	i = 0;
	while (i < n - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (j + n);
}
