#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	**ft_col_malloc(char **map, int col, int row)
{
	int		i;

	i = -1;
	while (++i < row)
	{
		map[i] = (char *)malloc(sizeof(char) * col + 1);
		if (map[i] == NULL)
			return (0);
	}
	return (map);
}

char	**ft_col_mapping(char **map, char *buf, int row)
{
	int		i;
	int		col;
	int		count;

	i = 0;
	col = 0;
	count = 0;
	while (*(buf + i) != '\n')
		i++;
	while (*(buf + ++i) != '\n')
		col++;
	while (*(buf + ++i))
	{
		if (*(buf + i) == '\n' && col == count)
			count = 0;
		else if (*(buf + i) == '\n' && col != count)
		{
			write(1, "Map_Error\n", 10);
			return (0);
		}
		else
			count++;
	}
	map = ft_col_malloc(map, col, row);
	return (map);
}

char	**ft_fill_data(char **map, char *buf, int row)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*buf != '\n')
		buf++;
	while (i < row - 1)
	{
		if (*(++buf) == '\n')
		{
			map[i][j] = '\0';
			j = 0;
			i++;
		}
		else
		{
			map[i][j] = *buf;
			j++;
		}
	}
	map[i][0] = '\0';
	return (map);
}

void	ft_print(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i][0])
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		ft_atoi(char *buf)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (*(buf + i) >= '0' && *(buf + i) <= '9')
	{
		result = result * 10 + *(buf + i) - '0';
		i++;
	}
	return (result);
}

char	**ft_mapping(void)
{
	int		fd;
	char	buf[1000000];
	char	**map;
	int		row;

	fd = open("samples.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	read(fd, buf, 1000000);
	row = ft_atoi(buf);
	map = (char **)malloc(sizeof(char *) * (row + 1));
	if (map == NULL)
	{
		write(1, "Mapping_Error\n", 14);
		return (0);
	}
	map = ft_col_mapping(map, buf, row + 1);
	map = ft_fill_data(map, buf, row + 1);
	close(fd);
	return (map);
}
