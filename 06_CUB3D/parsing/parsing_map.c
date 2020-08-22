/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:18:36 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:18:37 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

extern int	**g_map;

int			row_count(char *file, t_param *param)
{
	int		i;
	int		fd;
	int		re;
	int		count;
	char	str[BUFFER_SIZE];

	if ((fd = open(file, O_RDONLY)) < 0)
		return (error(NULL, 4));
	count = 0;
	while ((re = read(fd, str, BUFFER_SIZE)) > 0)
	{
		i = -1;
		while (++i < re)
		{
			if (str[i] == '\n')
				count++;
		}
	}
	close(fd);
	return (count);
}

int			row_malloc(t_param *param)
{
	int		max_row;

	max_row = param->mapheight;
	if (!(g_map = (int **)malloc(sizeof(int *) * (max_row + 1))))
		return (error(param, 5));
	g_map[max_row] = 0;
	if (!(param->mapwidth = (int *)malloc(sizeof(int) * (max_row + 1))))
		return (error(param, 5));
	param->mapwidth[max_row] = 0;
	return (1);
}

int			col_malloc(int row, char *line, t_param *param)
{
	int		i;

	i = ft_strlen(line);
	if (!(g_map[row] = (int *)malloc(sizeof(int) * (i + 1))))
		return (error(param, 5));
	g_map[row][i] = 0;
	param->mapwidth[row] = i;
	return (i);
}

int			put_map(int row, t_param *param, char *line)
{
	int		i;
	int		col;
	int		num;

	if (!row && !row_malloc(param))
		return (0);
	if (!(col = col_malloc(row, line, param)))
		return (0);
	i = -1;
	while (++i < col)
	{
		if (line[i] >= '0' && line[i] <= '9')
			g_map[row][i] = line[i] - '0';
		else if (line[i] == ' ')
			g_map[row][i] = 0;
		else if (line[i] == 'S' || line[i] == 'W'
				|| line[i] == 'N' || line[i] == 'E')
			set_coord(param, row, i, line[i]);
		else
			return (0);
	}
	return (i);
}

int			read_map(char *file, t_param *param)
{
	int		fd;
	int		row;
	char	*line;

	if (!(param->mapheight = row_count(file, param)))
		return (0);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (error(param, 4));
	row = 0;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'R')
			parse_r(param, line);
		else if (line[0] == 'F')
			parse_f(param, line);
		else if (line[0] == 'C')
			parse_c(param, line);
		else
			parse(&row, param, line);
	}
	return (row);
}
