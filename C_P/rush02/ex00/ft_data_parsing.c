/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:30:33 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/09 23:30:37 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_total.h"

void	ft_strcpy(char *dest, char *from, char *to)
{
	while (from < to)
		*(dest++) = *(from++);
	*dest = 0;
}

void	ft_split(char *str, t_data *data)
{
	int		i;
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

int		ft_in_data(t_data *data, char *str, int count)
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

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		ft_print("FAILED\n", 0);
		return (0);
	}
	count = 0;
	num = 0;
	buf = (char*)malloc(10000);
	read(fd, buf, 1000);
	while (*(buf + num))
	{
		if (*(buf + num) == '\n')
			count++;
		num++;
	}
	close(fd);
	return (count);
}

int		ft_fill_data(char *buf, t_data *data)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (*(buf + j))
	{
		if (*(buf + j) != '\n' && *(buf + j) != '\0')
			j++;
		else
		{
			if (ft_validate_value(buf + i) != 0)
			{
				ft_split(buf + i, &data[k++]);
				i = j + 1;
				j++;
			}
			else
				return (0);
		}
	}
	return (1);
}
