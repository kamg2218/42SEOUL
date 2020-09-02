/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:25:25 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/03 21:18:41 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			coordinate(t_param *param, t_coord *coord, t_img *img)
{
	int			x;
	t_map		map;
	double		camerax;
	double		p[param->x_rdr];

	x = -1;
	while (++x < param->x_rdr)
	{
		map.mapx = (int)coord->posx;
		map.mapy = (int)coord->posy;
		camerax = 2 * x / (double)param->x_rdr - 1;
		map.raydir_x = coord->dirx + coord->planex * camerax;
		map.raydir_y = coord->diry + coord->planey * camerax;
		calculate_deltadist(&map);
		coord->side = dda(coord, &map);
		p[x] = height(coord->side, param, &map);
		color(x, param, &map, coord->side);
	}
	color_sprite(p, param);
	if (param->save == 1)
		save_bmp(param);
}

int				game(t_param *param)
{
	int			x;
	int			y;

	x = -1;
	while (++x < param->y_rdr)
	{
		y = -1;
		while (++y < param->x_rdr)
			param->img.data[y * param->y_rdr + x] = 0;
	}
	mlx_hook(param->win, KEY_PRESS, 0, &read_key, param);
	mlx_hook(param->win, KEY_EXIT, 0, &red_cross, param);
	coordinate(param, &param->coord, &param->img);
	mlx_put_image_to_window(param->mlx, param->win, param->img.img, 0, 0);
	return (0);
}

int				preprocess(int argc, char **argv, t_param *param)
{
	if (argc <= 1 || argc > 3)
		return (error(NULL, 1));
	if (!(ft_endwidth(argv[1], ".cub")))
		return (error(NULL, 2));
	if (argc > 2)
	{
		if ((ft_endwidth(argv[2], ".cub")))
			return (error(NULL, 2));
		if (!(ft_memcmp(argv[2], "--save", 5)))
			param->save = 1;
		else
			return (error(NULL, 1));
	}
	param->sprite = NULL;
	param->img.img = NULL;
	param->x_rdr = SCREENWIDTH;
	param->y_rdr = SCREENHEIGHT;
	return (1);
}

int				main(int argc, char **argv)
{
	int			i;
	void		*data;
	t_img		img;
	t_param		param;

	param.mlx = mlx_init();
	if (!(preprocess(argc, argv, &param)))
		return (0);
	if (!(read_xpm(&param)))
		return (error(&param, 3));
	if (!(parse_map(argv[1], &param)))
		return (error(&param, 4));
	param.win = mlx_new_window(param.mlx, param.x_rdr, param.y_rdr, "cub3D");
	img.img = mlx_new_image(param.mlx, param.x_rdr, param.y_rdr);
	data = mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
	param.img.data = (int *)data;
	param.img.img = img.img;
	mlx_loop_hook(param.mlx, &game, &param);
	mlx_loop(param.mlx);
	return (0);
}
