#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		len;
	
	if (min >= max)
		return (0);
	len = max - min;
	*range = (int*)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (len);
}

int main()
{
	int		*pointer;
	int		len;

	len = ft_ultimate_range(&pointer, 6, 12);
	for (int i = 0; i < len; i++)
		printf("%d ", pointer[i]);
	return (0);
}
