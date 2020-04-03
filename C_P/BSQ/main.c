#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	**ft_col_malloc(char **map, int col, int row);
char	**ft_col_mapping(char **map, char *buf, int row);
char	**ft_fill_data(char **map, char *buf, int row);
void	ft_print(char **map);
char	**ft_mapping(void);
int		ft_atoi(char *buf);

void	ft_print_map(char **map, int i, int j, int size)
{
	int		row;
	int		col;

	row = 0;
	while (map[row][0])
	{
		col = 0;
		while (map[row][col])
		{
			if (row >= i && row < i + size
					&& col >= j && col < j + size)
				write(1, "X", 1);
			else
				write(1, &map[row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int		ft_check(char **map, int i, int j, int box_size)
{
	int		k;
	int		l;
	
	l = i;
	while (l < i + box_size)
	{
		k = j;
		while (k < j + box_size)
		{
			if (map[l][k] == 'o')
				return (0);
			k++;
		}
		l++;
	}
	return (1);
}

int		ft_move(char **map, int box_size, int map_size)
{
	int		j;
	int		i;
	
	i = 0;
	while (i <= map_size - box_size)
	{
		j = 0;
		while (j <= map_size - box_size)
		{
			if(ft_check(map, i, j, box_size) == 1)
			{
				ft_print_map(map, i, j, box_size);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
int		main()
{
	int		i;
	char	**map;
	int		map_size;
	int		box_size;

	i = 0;
	map_size = 0;
	map = ft_mapping();
	ft_print(map);
	write(1, "\n", 1);
	while (map[0][i] != '\0')
	{
		map_size++;
		i++;
	}
	box_size = map_size;
	while (box_size <= map_size)
	{
		if (box_size == 0)
		{
			write(1, "Failed to make box\n", 19);
			ft_print(map);
			break ;
		}
		if (ft_move(map, box_size, map_size) == 1)
			break ;
		box_size--;
	}
	free(map);
	return (0);
}
