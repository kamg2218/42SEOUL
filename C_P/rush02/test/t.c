#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int     ft_is_space(char *str);
int     ft_is_non_printable(char *str);
int     ft_is_numeric(char c);
int     ft_validate_key(char *str);
int     ft_validate_value(char *str);
int     ft_validate_dict(char *str);


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

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int		result;
	int		j;

	j = 0;
	result = 0;
	while (j < 2)
	{
		result = result * 10 + (str[j] - '0');
		j++;
	}
	return (result);
}

int		ft_in_data(DATA *data, char *str, int count)
{
	int		i;

	i = 0;
	while (i < count + 1)
	{
		if (ft_strcmp(data[i].key, str) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_three(DATA *data, char *str, int n, int count)
{
	int		i;
	int		num;

	i = 0;
	if (ft_in_data(data, str, count))
	{
		printf("%s ", data[i].value);
		return ;
	}
	i = 0;
	if (str[0] != '0')
	{
		i = str[0] - '0';
		printf("%s ", data[i].value);
		printf("%s ", data[28 + n].value);
	}
	num = ft_atoi(&str[1]);
	if (num <= 20)
		printf("%s ", data[num + 1].value);
	else
	{
		printf("%s ", data[num / 10 + 19].value);
		printf("%s\n", data[num % 10].value);
	}
	return ;
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
			i++;
		else if (j == 0)
		{
			from = i;
			while (*(str + i) != '\n' && *(str + i) != ':'
					&& !ft_is_space(str + i))
				i++;
			ft_strcpy(data->key, str + from, str + i);
			j = 1;
		}
		else
		{
			from = i;
			while (*(str + i) != '\n' && !ft_is_non_printable(str + i))
				i++;
			ft_strcpy(data->value, str + from, str + i);
		}
	}
}

char    **ft_str_cut(char *str)
{
    int length;
    int digit;
    int one_digit;
    char *number;
    char **numbers;
    int index;
    int index2;
    int index3;
    int i;

	i = 0;
    index = 0;
    index2 = 0;
    index3 = 0;
    length = 0;
    while (*(str + length))
        length++;
    digit = (length - 1) / 3;
    one_digit = length % 3;
    numbers = (char **)malloc(sizeof(char*) * (digit + 3));
    while (i < digit + 3)
    {
        numbers[i] = (char *)malloc(sizeof(char) * 3 + 1);
        i++;
    }
    int zero_count = 0;
    while (*(str + index))
    {
        while (one_digit + zero_count < 3 && one_digit != 0)
        {
            *(numbers[index2] + index3) = '0';
            index3++;
            zero_count++;
        }
        *(numbers[index2] + index3) = *(str + index);
        if (index == one_digit - 1)
        {
            index2++;
            index3 = -1;
        }
        else if ((index - one_digit +1) % 3 == 0)
        {
            index2++;
            index3 = -1;
        }
        index3++;
        index++;
    }
    *(numbers + index2) = 0;
    return (numbers);
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		i;
	int		j;
	int		k;
	int		num;
	int		count;
	int		len;
	char	*buf;
	char	**cut;
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
		else if (!ft_validate_key(buf + i))
			return (0);
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
	len = ft_strlen(argv[1]);
	while (i < count)
	{
		if (ft_strcmp(data[i].key, argv[1]) == 0)
		{
			printf("%s\n", data[i].value);
			close(fd);
			return (0);
		}
		i++;
	}
	i = 0;
	cut = ft_str_cut(argv[1]);
	while (cut[i])
	{
		ft_print_three(data, cut[i], (len / 3) - i, count);
		i++;
	}

	close(fd);
	return (0);
}
