/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_parsing2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:30:45 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/09 23:35:26 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_total.h"

t_data	*ft_initialize(void)
{
	int		fd;
	char	*buf;
	t_data	*data;

	if (mal_len() == 0)
		return (0);
	fd = open("numbers.dict", O_RDONLY);
	buf = (char*)malloc(10000);
	read(fd, buf, 1000);
	data = (t_data *)malloc(sizeof(t_data) * (mal_len() + 1));
	if (ft_fill_data(buf, data) == 0)
		return (0);
	return (data);
}

void	ft_cut(t_data *data, char *str)
{
	int		i;
	char	**cut;

	i = 0;
	if (ft_full_check(data, str) != 1)
	{
		cut = ft_str_cut(str);
		i = -1;
		while (cut[++i])
		{
			ft_sam(data, cut[i], ((ft_strlen(str) - 1) / 3) - i);
			if (i != ((ft_strlen(str) - 1) / 3))
				write(1, " ", 1);
		}
	}
	return ;
}

int		ft_numeric_check(char *argv)
{
	int	j;

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

void	ft_sam_check(t_data *data, int n)
{
	if (n != 0)
	{
		write(1, " ", 1);
		ft_print(data[28 + n].value, 0);
	}
	return ;
}
