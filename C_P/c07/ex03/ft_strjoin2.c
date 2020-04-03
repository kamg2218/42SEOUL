#include <stdlib.h>

int		ft_strlen(int size, char **strs)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{	
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*l_str;
	
	if (size == 0)
	{
		l_str = (char*)malloc(sizeof(char));
		l_str[0] = '\0';
		return (l_str);
	}
	len = ft_strlen(size, strs);
	l_str = (char*)malloc(sizeof(char) * (len + size));
	i = 0;
	while (i < size)
	{
		ft_strcat(l_str, strs[i]);
		if (i != size - 1)
			ft_strcat(l_str, sep);
		i++;
	}
	return (l_str);
}

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int		index;
	char	**strs;
	char	*sep;
	char	*result;

	strs = (char **)malloc(5 * sizeof(strs));
	strs[0] = "Hello";
	strs[1] = "My";
	strs[2] = "Name";
	strs[3] = "Is";
	strs[4] = "HaKim";
	sep = "+";
	index = 0;
	while (index < 6)
	{
		result = ft_strjoin(index, strs, sep);
		printf("result with size = %d : $%s$\n", index, result);
		index++;
	}
	return (0);
}
