#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct num_data
{
	char key[10000];
	char value[10000];
}DATA;

void	ft_strcpy(char *dest, char *from, char *to)
{
	while (from < to)
		*(dest++) = *(from++);
	*dest = 0;
}
int		ft_is_space(char *str)
{
	if (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f'
			|| *str == '\r')
		return (1);
	else if (*str < 32 || *str > 126)
		return (1);
	else
		return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_split(char *str, DATA *data)
{
	int		i;
	int		j;
	int		from;
	
	i = 0;
	j = 0;
	while (*(str+i) != '\n')
	{
		if (ft_is_space(str + i))
		{
			i++;
			continue ;
		}
		if (*(str + i) != ':')
		{
			from = i;
			while (*(str + i) != '\n' && *(str + i) != ':')
			{
				if (ft_is_space(str + i))
					break ;
				else
					i++;
			}
			if (j == 0)
			{
				ft_strcpy(data->key, str + from, str + i);
				j = 1;
			}
			else
				ft_strcpy(data->value, str + from, str + i);
		}
		else
			i++;
	}
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		i;
	int		j;
	int		k;
	int		num;
	int		count;
	char	*buf;
	DATA	*data;

	fd = open("samples.txt", O_RDONLY);
	if (fd == -1)
	{	printf("FAILED\n");
		exit(1);
	}
	count = 0;
	num = 0;
	buf = (char*)malloc(10240);
	read(fd, buf, 1000);
	while(*(buf + num))
	{
		if (*(buf + num) == '\n')
			count++;
		num++;
	}
	printf("%d\n", count);
	data = (DATA *)malloc(sizeof(DATA) * (count + 1));
	i = 0;
	j = 0;
	k = 0;
	while (*(buf + j))
	{
		if (*(buf + j) != '\n' && *(buf + j) != '\0')
			j++;
		else
		{
			ft_split(buf + i, &data[k]);
			i = j + 1;
			k++;
			j++;
		}
	}
	
	if (argc != 2 && argc != 3)
		return (0);

	i = 0;
	while (1)
	{
		if (ft_strcmp(data[i].key, argv[1]) == 0)
		{
			printf("%s\n", data[i].value);
			break ;
		}
		i++;
	}
	close(fd);
	return (0);
}
