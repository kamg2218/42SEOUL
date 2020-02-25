#include <unistd.h>

void	*memcpy(void *destination, const void *source, size_t num)
{
	unsigned int		i;
	char	c;

	i = 0;
	while (i < num)
	{
		if (!*((char *)source + i))
			c = 0;
		else
			c = *((char *)source + i);
		*((char *)destination + i) = c;
		i++;
	}
	return (destination);
}
