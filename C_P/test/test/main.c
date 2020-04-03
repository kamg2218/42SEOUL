/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:56:34 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/09 23:01:17 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		mal_len(void)
{
	int		fd;
	int		num;
	int		count;
	char	*buf;
	DATA	*data;

	fd = open("samples.txt", O_RDONLY);
	if (fd == -1)
	{	printf("FAILED\n");
		return (0);
	}
	count = 0;
	num = 0;
	buf = (char*)malloc(10000);
	read(fd, buf, 1000);
	while(*(buf + num))
	{
		if (*(buf + num) == '\n')
			count++;
		num++;
	}
	close(fd);
	return (count);
}

int		ft_full_check(DATA *data, char *argv)
{
	int		i;

	i = 0;
	while (i < mal_len())
	{
		if (ft_strcmp(data[i].key, argv) == 0)
		{
			printf("%s\n", data[i].value);
			return (i);
		}
		i++;
	}
	return (0);
}

void	ft_sam(DATA *data, char *str, int n, int count)
{
	int		i;
	int		j;
	int		k;
	char	c_num[4];

	i = 0;
	while (i < 3)
	{
		if (ft_full_check(data, str) != 0)
			i = 3;
		else
		{
			j = 0;
			c_num[j] = str[i];
			while (++j < 3 - i)
			{
				c_num[j] = '0';
			}
			c_num[j] = '\0';
			printf("\n%s\n", c_num);
			k = ft_full_check(data, c_num);
		}
		i++;
	}
	if (n != 0)
	{
		printf("%s - ", data[28 + n].value);
	}
	return ;
}

void	ft_split(char *str, DATA *data)
{
	int		i;
	int		j;
	int		from;
	i = 0;
	from = 0;
	while (ft_is_numeric(*(str + i)))
		i++;
	ft_strcpy(data->key, str, str + i);
	while (*(str + i) != ':')
		i++;
	while (ft_is_space(str + i + 1))
		i++;
	from = i + 1;
	while (!ft_is_non_printable(str + i) && *(str + i) != '\n')
		i++;
	ft_strcpy(data->value, str + from, str + i);
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
/*
int		mal_len(void)
{
	int		fd;
	int		num;
	int		count;
	char	*buf;
	DATA	*data;
	
	fd = open("samples.txt", O_RDONLY);
	if (fd == -1)
	{	printf("FAILED\n");
		return (0);
	}
	count = 0;
	num = 0;
	buf = (char*)malloc(10000);
	read(fd, buf, 1000);
	while(*(buf + num))
	{
		if (*(buf + num) == '\n')
			count++;
		num++;
	}
	close(fd);
	return (count);
}
*/
int		ft_fill_data(char *buf, DATA *data)
{
	int		i;
	int		j;
	int		k;
	int		valid;

	i = 0;
	j = 0;
	k = 0;
	while (*(buf + j))
	{
		if (*(buf + j) != '\n' && *(buf + j) != '\0')
			j++;
		else
		{
			valid = ft_validate_value(buf + i);
			if (valid != 0)
			{
				ft_split(buf + i, &data[k]);
				i = j + 1;
				k++;
				j++;
			}
			else
				return (0);
		}
	}
	return (1);
}

/*int		ft_full_check(DATA *data, char *argv)
{
	int		i;

	i = 0;
	while (i < mal_len())
	{
		if (ft_strcmp(data[i].key, argv) == 0)
		{
			printf("%s\n", data[i].value);
			return (i);
		}
		i++;
	}
	return (0);
}*/

DATA	*ft_initialize(void)
{
	int		fd;
	int		i;
	char	*buf;
	char	**cut;
	DATA	*data;

	if (mal_len() == 0)
		return (0);
	fd = open("samples.txt", O_RDONLY);
	buf = (char*)malloc(10240);
	read(fd, buf, 1000);
	data = (DATA *)malloc(sizeof(DATA) * (mal_len() + 1));
	if (ft_fill_data(buf, data) == 0)
		return (0);
	return (data);
}

void	ft_cut(DATA *data, char *str)
{
	int		i;
	char	**cut;

	if (ft_full_check(data, str) == 0)
	{
		cut = ft_str_cut(str);
		i = -1;
		while (cut[++i])
			ft_sam(data, cut[i], ((ft_strlen(str) - 1) / 3) - i, mal_len());
	}
	return ;
}

int		argv_numeric_check(char *argv)
{
	int j;
	j = 0;
	while (argv[j] != 0)
	{
		if (!ft_is_numeric(argv[j]))
			return (1);
		else
			return (0);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;
	DATA	*data;

	if (argc == 1)
		return (0);
	if (argv_numeric_check(argv[1]) != 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}	
	data = ft_initialize();
	if (data == 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	ft_cut(data, argv[1]);
	free(data);
	return (0);
}
