/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:18:50 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:18:51 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int			**g_map;

void		xpm_to_image(int i, char *file, t_param *param)
{
	int		width;
	int		height;
	void	*image;
	t_img	new;

	if (param->img.buff[i] != NULL)
		free(param->img.buff[i]);
	width = 64;
	height = 64;
	new.img = mlx_xpm_file_to_image(param->mlx, file, &width, &height);
	image = mlx_get_data_addr(new.img, &new.bpp, &new.size_l, &new.endian);
	(param->img.buff)[i] = (int *)image;
}

int			read_xpm(t_param *param)
{
	int		i;

	if (!(param->img.buff = (int **)malloc(sizeof(int *) * 11)))
		return (error(param, 5));
	i = -1;
	while (++i < 11)
		param->img.buff[i] = NULL;
	(param->img.buff)[10] = 0;
	xpm_to_image(0, "textures/wall_1.xpm", param);
	xpm_to_image(1, "textures/wall_1.xpm", param);
	xpm_to_image(2, "textures/wall_1.xpm", param);
	xpm_to_image(3, "textures/wall_1.xpm", param);
	xpm_to_image(4, "textures/bluestone.xpm", param);
	xpm_to_image(5, "textures/pillar.xpm", param);
	xpm_to_image(6, "textures/wood.xpm", param);
	xpm_to_image(7, "textures/sprite_1.xpm", param);
	xpm_to_image(8, "textures/sprite_2.xpm", param);
	xpm_to_image(9, "textures/sprite_3.xpm", param);
	return (1);
}
