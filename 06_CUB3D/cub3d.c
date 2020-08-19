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
	double		perp;
	double		camerax;
	double		p[SCREENWIDTH];

	x = -1;
	while (++x < SCREENWIDTH)
	{
		map.mapx = (int)coord->posx;
		map.mapy = (int)coord->posy;
		camerax = 2 * x / (double)SCREENWIDTH - 1;
		map.raydir_x = coord->dirx + coord->planex * camerax;
		map.raydir_y = coord->diry + coord->planey * camerax;
		calculate_deltadist(&map);
		coord->side = dda(coord, &map);
		perp = height(coord->side, coord, &map);
		color(x, param, &map, coord->side);
		p[x] = perp;
	}
	color_sprite(p, param);
	if (param->save == 1)
		save_bmp(param);
	param->save = 0;
}

int				game(t_param *param)
{
	int			x;
	int			y;

	x = -1;
	while (++x < SCREENHEIGHT)
	{
		y = -1;
		while (++y < SCREENWIDTH)
			param->img.data[y * SCREENHEIGHT + x] = 0;
	}
	mlx_hook(param->win, KEY_PRESS, 0, &read_key, param);
	mlx_hook(param->win, KEY_EXIT, 0, &red_cross, param);
	coordinate(param, &param->coord, &param->img);
	mlx_put_image_to_window(param->mlx, param->win, (param->img).img, 0, 0);
	return (0);
}

int				preprocess(int argc, char **argv, t_param *param)
{
	if (argc <= 1 || argc > 3)
		return (error(param, 1));
	if (!(ft_endwidth(argv[1], ".cub")))
		return (error(param, 2));
	if (argc > 2)
	{
		if ((ft_endwidth(argv[2], ".cub")))
			return (error(param, 2));
		if (!(ft_memcmp(argv[2], "--save", 5)))
			param->save = 1;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	int			i;
	void		*data;
	t_img		img;
	t_param		param;

	if (!(preprocess(argc, argv, &param)))
		return (0);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
	img.img = mlx_new_image(param.mlx, SCREENWIDTH, SCREENHEIGHT);
	data = mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
	img.data = (int *)data;
	param.img = img;
	if (!(read_xpm(&param)))
		return (error(&param, 3));
	if (!(parse_map(argv[1], &param)))
		return (error(&param, 4));
	mlx_loop_hook(param.mlx, &game, &param);
	mlx_loop(param.mlx);
	return (0);
}
