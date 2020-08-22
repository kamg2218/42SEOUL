/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:11:34 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:16:51 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				**g_map;

int				img_tex_x(t_param *param, t_map *map, int side)
{
	int			tex_x;
	double		perp;
	double		step;
	double		wall_x;

	perp = calculate_perp(side, &param->coord, map);
	if (side == 0)
		wall_x = (param->coord).posy + perp * map->raydir_y;
	else
		wall_x = (param->coord).posx + perp * map->raydir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)64);
	if (side == 0 && map->raydir_x > 0)
		tex_x = 64 - tex_x - 1;
	if (side == 1 && map->raydir_y < 0)
		tex_x = 64 - tex_x - 1;
	return (tex_x);
}

int				calculate_temp(int side, t_map *map)
{
	int			temp;

	temp = g_map[map->mapx][map->mapy];
	if (temp != 1)
		return (temp + 2);
	else
	{
		if ((map->raydir_x >= 0 && map->raydir_y >= 0 && side)
				|| (map->raydir_x <= 0 && map->raydir_y >= 0 && side))
			return (0);
		else if ((map->raydir_x >= 0 && map->raydir_y <= 0 && side)
				|| (map->raydir_x <= 0 && map->raydir_y <= 0 && side))
			return (1);
		else if ((map->raydir_x >= 0 && map->raydir_y >= 0 && !side)
				|| (map->raydir_x >= 0 && map->raydir_y <= 0 && !side))
			return (2);
	}
	return (3);
}

int				wall(int texpos, int side, t_map *map, t_param *param)
{
	int			temp;
	int			tex_x;
	int			tex_y;

	tex_x = img_tex_x(param, map, side);
	tex_y = (int)texpos & 63;
	temp = calculate_temp(side, map);
	return (param->img.buff[temp][64 * tex_y + tex_x]);
}

void			color(int x, t_param *param, t_map *map, int side)
{
	int			pos;
	int			count_h;
	double		texpos;

	texpos = 0.0;
	count_h = -1;
	while (++count_h < SCREENHEIGHT)
	{
		pos = count_h * SCREENWIDTH + x;
		if (count_h >= map->drawstart && count_h <= map->drawend)
		{
			texpos += 64.0 / (SCREENHEIGHT - 2 * map->drawstart);
			param->img.data[pos] = wall(texpos, side, map, param);
		}
		else if (count_h < map->drawstart)
			param->img.data[pos] = param->c_color;
		else
			param->img.data[pos] = param->f_color;
	}
}
