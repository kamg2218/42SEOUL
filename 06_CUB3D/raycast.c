/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:17:39 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:17:41 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern int	**g_map;

void		sidedist(t_coord *coord, t_map *map)
{
	if (map->raydir_x < 0)
	{
		coord->stepx = -1;
		map->sidedist_x = (coord->posx - map->mapx) * map->deltadist_x;
	}
	else
	{
		coord->stepx = 1;
		map->sidedist_x = (map->mapx + 1.0 - coord->posx) * map->deltadist_x;
	}
	if (map->raydir_y < 0)
	{
		coord->stepy = -1;
		map->sidedist_y = (coord->posy - map->mapy) * map->deltadist_y;
	}
	else
	{
		coord->stepy = 1;
		map->sidedist_y = (map->mapy + 1.0 - coord->posy) * map->deltadist_y;
	}
}

int			dda(t_coord *coord, t_map *map)
{
	int		hit;
	int		side;

	sidedist(coord, map);
	hit = 0;
	while (hit == 0)
	{
		if (map->sidedist_x < map->sidedist_y)
		{
			map->sidedist_x += map->deltadist_x;
			map->mapx += coord->stepx;
			side = 0;
		}
		else
		{
			map->sidedist_y += map->deltadist_y;
			map->mapy += coord->stepy;
			side = 1;
		}
		if (g_map[map->mapx][map->mapy] > 0)
			hit = 1;
	}
	return (side);
}

double		calculate_perp(int side, t_coord *coord, t_map *map)
{
	double	step;
	double	perp_dist;

	if (side == 1)
	{
		step = (1 - coord->stepy) / 2;
		perp_dist = (map->mapy - coord->posy + step) / map->raydir_y;
	}
	else
	{
		step = (1 - coord->stepx) / 2;
		perp_dist = (map->mapx - coord->posx + step) / map->raydir_x;
	}
	return (perp_dist);
}

double		height(int side, t_coord *coord, t_map *map)
{
	int		h;
	int		lineheight;
	double	perp_dist;

	perp_dist = calculate_perp(side, coord, map);
	h = SCREENHEIGHT;
	lineheight = (int)(h / perp_dist);
	map->drawstart = -lineheight / 2 + h / 2;
	if (map->drawstart < 0)
		map->drawstart = 0;
	map->drawend = lineheight / 2 + h / 2;
	if (map->drawend >= h || map->drawend < 0)
		map->drawend = h - 1;
	return (perp_dist);
}

void		calculate_deltadist(t_map *map)
{
	if (map->raydir_x == 0)
	{
		map->deltadist_x = 1;
		map->deltadist_y = 0;
	}
	else if (map->raydir_y == 0)
	{
		map->deltadist_x = 0;
		map->deltadist_y = 1;
	}
	else
	{
		map->deltadist_x = fabs(1 / map->raydir_x);
		map->deltadist_y = fabs(1 / map->raydir_y);
	}
}
