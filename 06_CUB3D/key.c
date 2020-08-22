/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:02:53 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/03 21:32:10 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			**g_map;

void		rotate(double theta, t_coord *coord)
{
	double	x;

	x = coord->dirx;
	coord->dirx = cos(theta) * x - sin(theta) * coord->diry;
	coord->diry = sin(theta) * x + cos(theta) * coord->diry;
	x = coord->planex;
	coord->planex = cos(theta) * x - sin(theta) * coord->planey;
	coord->planey = sin(theta) * x + cos(theta) * coord->planey;
}

void		move_front(int keycode, t_coord *coord)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		if (coord->dirx != 0
				&& !g_map[(int)(coord->posx + coord->dirx)][(int)coord->posy])
			coord->posx += coord->dirx;
		if (coord->diry != 0
				&& !g_map[(int)coord->posx][(int)(coord->posy + coord->diry)])
			coord->posy += coord->diry;
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		if (coord->dirx != 0
				&& !g_map[(int)(coord->posx - coord->dirx)][(int)coord->posy])
			coord->posx -= coord->dirx;
		if (coord->diry != 0
				&& !g_map[(int)coord->posx][(int)(coord->posy - coord->diry)])
			coord->posy -= coord->diry;
	}
}

void		move_side(int keycode, t_coord *coord)
{
	if (keycode == KEY_A)
	{
		if (!g_map[(int)(coord->posx - coord->diry)][(int)coord->posy])
			coord->posx -= coord->diry;
		if (!g_map[(int)coord->posx][(int)(coord->posy + coord->dirx)])
			coord->posy += coord->dirx;
	}
	else if (keycode == KEY_D)
	{
		if (!g_map[(int)(coord->posx + coord->diry)][(int)coord->posy])
			coord->posx += coord->diry;
		if (!g_map[(int)coord->posx][(int)(coord->posy - coord->dirx)])
			coord->posy -= coord->dirx;
	}
}

int			read_key(int keycode, t_param *param)
{
	if (keycode == KEY_W || keycode == KEY_UP
			|| keycode == KEY_S || keycode == KEY_DOWN)
		move_front(keycode, &(param->coord));
	else if (keycode == KEY_A || keycode == KEY_D)
		move_side(keycode, &(param->coord));
	else if (keycode == KEY_LEFT)
		rotate(0.1, &(param->coord));
	else if (keycode == KEY_RIGHT)
		rotate(-0.1, &(param->coord));
	else if (keycode == KEY_ESC)
		exit_game(param);
	return (0);
}

int			red_cross(t_param *param)
{
	exit_game(param);
	return (0);
}
