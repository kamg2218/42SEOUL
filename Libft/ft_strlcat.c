unsigned int	ft_strlcat(char *dst, const char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	j = 0;
	while (src[j])
		j++;
	i = 0;
	while (dst[i])
		i++;
	k = i + j;
	j = 0;
	while (j < n - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (k);
}
