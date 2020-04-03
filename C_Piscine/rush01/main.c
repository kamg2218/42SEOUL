#include <stdio.h>
#include <unistd.h>

void    set_zero(int *a);
int		check_row(int *map, int i_argvL, int i_argvR);
int		count_row(int *map, int bl);
int		check_col(int *map, int i_argvU, int i_argvD);
int		count_col(int *map, int bl);
void	swap(int *a, int *b);
int		next_permutation(int *a, int n);
int		set_row(int *map, int *i_argv, int row_n);

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		map[17];
	int		i_argv[17];

	i = 0;
	while (argv[1][i])
		i++;
	if (argc != 2 || i != 31)
	{
		write(1, "ERROR", 5);
		return (0);
	}
	i = 0;
	while (i < 32)
	{
		i_argv[i / 2] = argv[1][i] - '0';
		i += 2;
	}
	set_zero(map);
	set_row(map, i_argv, 0);
	for (int j = 0; j < 16; j++)
	{
		printf("%d ", map[j]);
		if (j % 4 == 3) printf("\n");
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		if (!check_col(&map[i * 4], i_argv[8 + i], i_argv[12 + i]))
		{
			while (1)
			{
				if (j > 3)
				{
					write(1, "ERROR", 5);
					return (0);
				}
				else if(!set_row(map, i_argv, 3 - j))
				{
					set_row(map, i_argv, 3 - j);
					j++;
				}
				else
				{
					i = 0;
					break ;
				}
			}
		}
		else
			i++;
	}

	for (int j = 0; j < 16; j++)
	{
		printf("%d ", map[j]);
		if (j % 4 == 3) printf("\n");
	}
/*
	set_row(map, i_argv, 0);
	for (int j = 0; j < 16; j++)
	{
		printf("%d ", map[j]);
		if (j % 4 == 3) printf("\n");
	}
	set_row(map, i_argv, 2);
	for (int j = 0; j < 16; j++)
	{
		printf("%d ", map[j]);
		if (j % 4 == 3) printf("\n");
	}*/
	/*
	i = 1;
	for (int j = 0; j < 9; j++){
	next_permutation(&map[i * 4], 4);
	}
	printf("%d\n", check_row(&map[i * 4], i_argv[8 + i], i_argv[12 + i]));
	for (int j = 0; j < 16; j++)
	{
		printf("%d ", map[j]);
		if (j % 4 == 3) printf("\n");
   	}
	*/
	return (1);
}
int		set_row(int *map, int *i_argv, int row_n)
{
	int		j;

	while (row_n < 4)
	{
		if (row_n < 0)
			return (0);
		else if (!next_permutation(&map[row_n * 4], 4))
		{
			j = -1;
			while (++j < 4)
				map[row_n * 4 + j] = 0;
			row_n--;
		}
		else if (check_row(&map[row_n * 4], i_argv[8 + row_n], i_argv[12 + row_n]))
			row_n++;
		else
			continue ;
	}
	return (1);
}
void	set_zero(int *a)
{
	int		i;

	i = -1;
	while (++i < 16)
		a[i] = 0;
}

int		count_row(int *map, int bl)
{
	int		i;
	int		j;
	int		max;
	int		count;

	i = 0;
	j = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (bl == 1)
			j = 3 - i;
		else
			j = i;
		if (map[j] > max)
		{
			max = map[j];
			count += 1;
		}
		i++;
	}
	return (count);
}
int		check_row(int *map, int i_argvL, int i_argvR)
{
	int		count_L;
	int		count_R;

	count_L = count_row(map, 0);
	count_R = count_row(map, 1);
	if (count_L == i_argvL && count_R == i_argvR)
		return (1);
	else
		return (0);
}

int		count_col(int *map, int bl)
{
	int		i;
	int		j;
	int		max;
	int		count;

	i = 0;
	j = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (bl == 1)
			j = 3 - i;
		else
			j = i;
		if (map[j * 4] > max)
		{
			max = map[j * 4];
			count += 1;
		}
		i++;
	}
	return (count);
}

int		check_col(int *map, int i_argvU, int i_argvD)
{
	int		count_U;
	int		count_D;

	count_U = count_col(map, 0);
	count_D = count_col(map, 1);
	if (count_U == i_argvU && count_D == i_argvD)
		return (1);
	else
		return (0);
}
