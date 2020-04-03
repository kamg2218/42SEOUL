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

char	*ft_fill_str(int size, char **strs, char *sep, char *l_str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			l_str[++k] = strs[i][j];
			j++;
		}
		if (i != size - 1)
			l_str[++k] = *sep;
		i++;
	}
	l_str[++k] = '\0';
	return (l_str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
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
	if (l_str == 0)
		return (0);
	l_str = ft_fill_str(size, strs, sep, l_str);
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
