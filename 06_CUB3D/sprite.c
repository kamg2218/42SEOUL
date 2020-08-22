/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:17:45 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:17:47 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			switch_sprite(t_sprite *sprite, int i, int j)
{
	t_sprite	tmp;

	tmp.texture = sprite[i].texture;
	tmp.x = sprite[i].x;
	tmp.y = sprite[i].y;
	sprite[i].texture = sprite[j].texture;
	sprite[i].x = sprite[j].x;
	sprite[i].y = sprite[j].y;
	sprite[j].texture = tmp.texture;
	sprite[j].x = tmp.x;
	sprite[j].y = tmp.y;
}

int				dist_sprite(double **dist, t_param *param)
{
	int			i;
	double		x;
	double		y;

	i = 0;
	while (param->sprite[i].texture != 0)
		i++;
	if (!(*dist = (double *)malloc(sizeof(double) * (i + 1))))
		return (error(param, 5));
	i = 0;
	while (param->sprite[i].texture != 0)
	{
		x = param->coord.posx - param->sprite[i].x;
		y = param->coord.posy - param->sprite[i].y;
		(*dist)[i] = x * x + y * y;
		i++;
	}
	(*dist)[i] = 0;
	return (1);
}

void			change_sprite(double *dist, t_param *param)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	while (dist[i])
	{
		j = i + 1;
		while (dist[j])
		{
			if (dist[i] < dist[j])
			{
				switch_sprite(param->sprite, i, j);
				k = dist[i];
				dist[i] = dist[j];
				dist[j] = k;
			}
			j++;
		}
		i++;
	}
}

int				sort_sprite(t_param *param)
{
	double		*dist;

	if (!(dist_sprite(&dist, param)))
		return (0);
	change_sprite(dist, param);
	free(dist);
	return (1);
}

int				transform_sprite(int i, t_param *param, double *txy)
{
	double		x;
	double		y;
	double		inv_det;
	t_coord		coord;

	coord = param->coord;
	x = coord.posx - param->sprite[i].x;
	y = coord.posy - param->sprite[i].y;
	inv_det = 1.0 / (coord.planex * coord.diry - coord.dirx * coord.planey);
	txy[0] = inv_det * (coord.dirx * y - coord.diry * x);
	txy[1] = inv_det * (coord.planey * x - coord.planex * y);
	return ((int)((SCREENWIDTH / 2) * (1 + txy[0] / txy[1])));
}
