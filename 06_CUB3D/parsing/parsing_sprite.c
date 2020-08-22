/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:18:42 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:18:45 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

extern int	**g_map;

int			count_sprite(t_param *param)
{
	int		row;
	int		col;
	int		count;

	row = -1;
	count = 0;
	while (++row < param->mapheight)
	{
		col = -1;
		while (++col < param->mapwidth[row])
		{
			if (g_map[row][col] == 3
					|| g_map[row][col] == 5
					|| g_map[row][col] == 6
					|| g_map[row][col] == 7)
				count++;
		}
	}
	return (count);
}

int			write_sprite(t_param *param)
{
	int		i;
	int		row;
	int		col;

	i = 0;
	row = -1;
	while (++row < param->mapheight)
	{
		col = -1;
		while (++col < param->mapwidth[row])
		{
			if (g_map[row][col] == 3
					|| g_map[row][col] == 5
					|| g_map[row][col] == 6
					|| g_map[row][col] == 7)
			{
				param->sprite[i].x = row;
				param->sprite[i].y = col;
				param->sprite[i].texture = g_map[row][col] + 2;
				g_map[row][col] = 0;
				i++;
			}
		}
	}
	return (1);
}

int			read_sprite(t_param *param)
{
	int		count;

	count = count_sprite(param);
	if (!(param->sprite = (t_sprite *)malloc(sizeof(t_sprite) * (count + 1))))
		return (error(param, 5));
	write_sprite(param);
	param->sprite[count].texture = 0;
	return (1);
}
