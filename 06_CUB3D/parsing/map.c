/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:39:06 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/11 20:51:26 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

extern int	**g_map;

void		exit_game(t_param *param)
{
	int		row;

	if (g_map)
	{
		row = -1;
		while (++row < param->mapheight)
			free(g_map[row]);
		free(g_map);
		if (param->mapwidth)
			free(param->mapwidth);
	}
	if (param->sprite)
		free(param->sprite);
	if (param->img.img)
		mlx_destroy_image(param->mlx, param->img.img);
	if (param->img.img && param->mlx && param->win)
		mlx_destroy_window(param->mlx, param->win);
	if (param->img.buff)
	{
		row = -1;
		while (++row < 10)
			free(param->img.buff[row]);
		free(param->img.buff);
	}
	exit(0);
}

int			error(t_param *param, int n)
{
	if (n == 1)
		perror("INPUT ERROR!");
	else if (n == 2)
		perror("MAP ERROR!");
	else if (n == 3)
		perror("FAIL TO READ XPM.");
	else if (n == 4)
		perror("FAIL TO PARSE MAP.");
	else if (n == 5)
		perror("FAIL TO ALLOCATE SPACES.");
	if (param == NULL)
	{
		exit(0);
		return (0);
	}
	exit_game(param);
	return (0);
}

void		put_coord(t_param *param, int dir_x, int dir_y)
{
	param->coord.dirx = dir_x;
	param->coord.diry = dir_y;
	if (dir_x != 0)
	{
		param->coord.planex = 0;
		if (dir_x > 0)
			param->coord.planey = -0.66;
		else
			param->coord.planey = 0.66;
	}
	else
	{
		if (dir_y > 0)
			param->coord.planex = 0.66;
		else
			param->coord.planex = -0.66;
		param->coord.planey = 0;
	}
}

void		set_coord(t_param *param, int row, int col, char dir)
{
	param->coord.posx = row;
	param->coord.posy = col;
	if (dir == 'E')
		put_coord(param, 0, 1);
	else if (dir == 'W')
		put_coord(param, 0, -1);
	else if (dir == 'S')
		put_coord(param, 1, 0);
	else
		put_coord(param, -1, 0);
	g_map[row][col] = 0;
}

int			parse_map(char *file, t_param *param)
{
	if (!(read_map(file, param)))
		return (error(param, 4));
	if (!(check_map(param)))
		return (error(param, 2));
	if (!(read_sprite(param)))
		return (error(param, 4));
	return (1);
}
