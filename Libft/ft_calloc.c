#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	i = malloc(size * count);
	if (i == NULL)
		return (0);
	return (i);
}
