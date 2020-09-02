/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:47:17 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/03 19:28:07 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

int					write_bmp_header(int fd, int filesize, t_param *param)
{
	int				i;
	int				tmp;
	unsigned char	bmpheader[54];

	i = 0;
	while (i < 54)
		bmpheader[i++] = (unsigned char)(0);
	bmpheader[0] = (unsigned char)('B');
	bmpheader[1] = (unsigned char)('M');
	set_int_in_char(bmpheader + 2, filesize);
	bmpheader[10] = (unsigned char)(54);
	bmpheader[14] = (unsigned char)(40);
	set_int_in_char(bmpheader + 18, param->x_rdr);
	set_int_in_char(bmpheader + 22, param->y_rdr);
	bmpheader[27] = (unsigned char)(1);
	bmpheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpheader, 54) < 0));
}

int					get_color(t_param *param, int x, int y)
{
	int				rgb;
	int				quo;
	int				color;

	quo = param->x_rdr * (param->y_rdr - 1 - y);
	color = *(int *)(param->img.data + quo + x);
	rgb = (color & 0xff0000) | (color & 0x00ff00) | (color & 0x0000ff);
	return (rgb);
}

int					write_bmp_data(int file, t_param *param, int pad)
{
	unsigned char	zero[3];
	int				i;
	int				j;
	int				color;

	zero[0] = 0;
	zero[1] = 0;
	zero[2] = 0;
	i = 0;
	while (i < param->y_rdr)
	{
		j = 0;
		while (j < param->x_rdr)
		{
			color = get_color(param, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int					save_bmp(t_param *param)
{
	int				filesize;
	int				file;
	int				pad;

	pad = (4 - (param->x_rdr * 3) % 4) % 4;
	filesize = 54 + (3 + (param->x_rdr + pad) * param->y_rdr);
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC)) < 0)
		return (0);
	if (!(write_bmp_header(file, filesize, param)))
		return (0);
	if (!(write_bmp_data(file, param, pad)))
		return (0);
	close(file);
	return (error(param, 0));
}
