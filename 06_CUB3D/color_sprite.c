/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:17:10 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:17:21 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_sprite(int n, int m, t_param *param)
{
	int		i;
	int		color;
	int		tex_x;
	int		drawy[2];

	tex_x = tex_x_sprite(n, m, drawy, param);
	i = drawy[0] - 1;
	while (++i < drawy[1])
	{
		color = coloringsprite(i, n, tex_x, param);
		if ((color & 0x00ffffff) != 0)
			param->img.data[i * param->x_rdr + m] = color;
	}
}

int			color_sprite(double *p, t_param *param)
{
	int		i;
	int		j;
	double	transform[2];
	int		screenx;
	int		drawx[2];

	if (!(sort_sprite(param)))
		return (0);
	i = -1;
	while (param->sprite[++i].texture != 0)
	{
		screenx = transform_sprite(i, param, transform);
		drawx[1] = draw_x(param, transform[1], &drawx[0], screenx);
		j = drawx[0] - 1;
		while (++j < drawx[1])
		{
			if ((j > 0 && j < param->x_rdr)
					&& (transform[1] > 0 && transform[1] < p[j]))
				draw_sprite(i, j, param);
		}
	}
	return (1);
}
