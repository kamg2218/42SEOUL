/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:32:55 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/03 20:59:32 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <math.h>
# include "parsing/map.h"

# define KEY_PRESS		2
# define KEY_EXIT		17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_DOWN		125
# define KEY_UP			126
# define KEY_CTRL		59

typedef struct			s_map
{
	int					mapx;
	int					mapy;
	int					drawstart;
	int					drawend;
	double				sidedist_x;
	double				sidedist_y;
	double				deltadist_x;
	double				deltadist_y;
	double				raydir_x;
	double				raydir_y;
}						t_map;

void					calculate_deltadist(t_map *map);
void					sidedist(t_coord *coord, t_map *map);
int						dda(t_coord *coord, t_map *map);
double					height(int side, t_param *param, t_map *map);
double					calculate_perp(int side, t_coord *coord, t_map *map);

void					color(int x, t_param *param, t_map *map, int side);
int						img_tex_x(t_param *param, t_map *map, int side);
int						calculate_temp(int side, t_map *map);
int						wall(int texpos, int side, t_map *map, t_param *param);

void					rotate(double theta, t_coord *coord);
void					move_side(int keycode, t_coord *coord);
void					move_front(int keycode, t_coord *coord);
int						read_key(int keycode, t_param *param);
int						red_cross(t_param *param);

int						game(t_param *param);
int						preprocess(int argc, char **argv, t_param *param);
void					coordinate(t_param *param, t_coord *coord, t_img *img);

int						sort_sprite(t_param *param);
int						dist_sprite(double **dist, t_param *param);
int						transform_sprite(int i, t_param *param, double *t_xy);
void					change_sprite(double *dist, t_param *param);
void					switch_sprite(t_sprite *sprite, int i, int j);

int						tex_x_sprite(int n, int m, int *drawy, t_param *param);
int						coloringsprite(int i, int n, int tex_x, t_param *param);
int						draw_y(t_param *param, double t_y, int *d_start, int w);
int						draw_x(t_param *param, double t_y, int *d_start, int x);

int						color_sprite(double *p, t_param *param);
void					draw_sprite(int i, int j, t_param *param);

void					set_int_in_char(unsigned char *start, int value);
int						save_bmp(t_param *param);
int						get_color(t_param *param, int x, int y);
int						write_bmp_data(int file, t_param *param, int pad);
int						write_bmp_header(int fd, int filesize, t_param *param);

#endif
