#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void    set_zero(int *square_A);
void	fill_in(int *values, int *square_A);
int		empty_space(int *square_A);

int		main(int argc, char *argv[])
{
	int		i;
	int		square_A[17];
	int		values[17];

	i = 0;
	while (argv[1][i])
		i++;
	printf("%d\n", i);
	if (argc != 2 || i != 31)
	{
		write(1, "ERROR", 5);
		printf("\n%s\n", argv[1]);
		return (0);
	}
	/*square_A = (int *)malloc(sizeof(int) * 16);
	if (square_A == NULL)
		write(1, "ERROR", 5);*/
	i = 0;
	while (i < 32)
	{
		values[i / 2] = argv[1][i] - '0';
		i += 2;
	}
	//메모리 할당
	set_zero(square_A);
	for (int j = 0; j < 16; j++)
		printf("%d", square_A[j]);
	printf("\n");
	fill_in(values, square_A);
	for (int j = 0; j < 16; j++){
		printf("%d", square_A[j]);
		if (j % 4 == 3)
			printf("\n");
	}
	/*i = 0;
	while (i < 16)
		write(1, &square_A[i], 1); 
	while (1)
	{
		fill_in(int *argv[], int *square_A);
		if (empty_space(square_A) == 0)
			break;
	}*/
	return (0);
}
//0으로 초기화
void	set_zero(int *square_A)
{
	int		i;

	i = -1;
	while (++i < 16)
		square_A[i] = 0;
}
//채워주는 함수
void	fill_in(int *values, int *square_A)
{
	int		i;
	int		j;

	i = 0;
	while (i < 16)
	{
		if (values[i] == 4)
		{
			j = 0;
			while (j < 16)
			{
				if (i < 8 && square_A[j] == 0 && i == j % 4)
					square_A[j] = j / 4 + 1;
				else if (i > 7 && square_A[j] == 0 && i % 4 == j / 4)
					square_A[j] = j % 4 + 1;
				j++;
			}
		}
		else if (values[i] == 1)
		{
			if (i >= 0 && i <= 3)
				square_A[i] = 4;
			else if (i >= 4 && i <= 7)
				square_A[i + 8] = 4;
			else if (i >= 8 && i <= 11)
				square_A[(i % 4) * 4] = 4;
			else if (i >= 12 && i <= 15)
				square_A[(i % 4) * 4 + 3] = 4;
		}
		i++;
	}
}
