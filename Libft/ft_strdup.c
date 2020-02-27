#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	while (s[i])
		i++;
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (dup == NULL)
		return (0);
	j = -1;
	while (++j <= i)
		dup[j] = s[j];
	return (dup);
}
