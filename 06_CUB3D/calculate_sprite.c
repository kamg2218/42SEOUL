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

void		draw_y(double t_y, int *d_start, int *d_end, int wh)
{
	int		len;

	len = abs((int)(SCREENHEIGHT / t_y));
	*d_start = -len / 2 + wh / 2;
	if (*d_start < 0)
		*d_start = 0;
	*d_end = len / 2 + wh / 2;
	if (*d_end >= wh)
		*d_end = wh - 1;
}

void		draw_x(double t_y, int *d_start, int *d_end, int x)
{
	int		len;

	len = abs((int)(SCREENHEIGHT / t_y));
	*d_start = -len / 2 + x;
	if (*d_start < 0)
		*d_start = 0;
	*d_end = len / 2 + x;
	if (*d_end >= SCREENWIDTH)
		*d_end = SCREENWIDTH - 1;
}

int			tex_x_sprite(int n, int m, int *drawy, t_param *param)
{
	int		wh;
	int		screenx;
	double	transform[2];

	screenx = transform_sprite(n, param, transform);
	draw_y(transform[1], &drawy[0], &drawy[1], SCREENHEIGHT);
	wh = abs((int)(SCREENHEIGHT / transform[1]));
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
	wh = abs((int)(SCREENHEIGHT / transform[1]));
	j = i * 256 - SCREENHEIGHT * 128 + wh * 128;
	tex_y = (int)((j * 64 / wh) / 256);
	color = param->img.buff[param->sprite[n].texture][64 * tex_y + tex_x];
	return (color);
}
