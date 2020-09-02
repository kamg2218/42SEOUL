/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:11:08 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:11:13 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			draw_y(t_param *param, double t_y, int *d_start, int w)
{
	int		len;
	int		d_end;

	len = abs((int)(param->y_rdr / t_y));
	*d_start = -len / 2 + w / 2;
	if (*d_start < 0)
		*d_start = 0;
	d_end = len / 2 + w / 2;
	if (d_end >= w)
		d_end = w - 1;
	return (d_end);
}

int			draw_x(t_param *param, double t_y, int *d_start, int x)
{
	int		len;
	int		d_end;

	len = abs((int)(param->y_rdr / t_y));
	*d_start = -len / 2 + x;
	if (*d_start < 0)
		*d_start = 0;
	d_end = len / 2 + x;
	if (d_end >= param->x_rdr)
		d_end = param->x_rdr - 1;
	return (d_end);
}

int			tex_x_sprite(int n, int m, int *drawy, t_param *param)
{
	int		wh;
	int		screenx;
	double	transform[2];

	screenx = transform_sprite(n, param, transform);
	drawy[1] = draw_y(param, transform[1], &drawy[0], param->y_rdr);
	wh = abs((int)(param->y_rdr / transform[1]));
	return ((int)((256 * (m - (-wh / 2 + screenx)) * 64 / wh) / 256));
}

int			coloringsprite(int i, int n, int tex_x, t_param *param)
{
	int		j;
	int		wh;
	int		tex_y;
	int		color;
	double	transform[2];

	transform_sprite(n, param, transform);
	wh = abs((int)(param->y_rdr / transform[1]));
	j = i * 256 - param->y_rdr * 128 + wh * 128;
	tex_y = (int)((j * 64 / wh) / 256);
	color = param->img.buff[param->sprite[n].texture][64 * tex_y + tex_x];
	return (color);
}
