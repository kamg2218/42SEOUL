#include <stdlib.h>

char  *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int    i;
	char            *sub;
	
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (0);
	i = - 1;
	while (++i < len)
		sub[i] = s[i + start];
	sub[i] = 0;
	return (sub);
}
