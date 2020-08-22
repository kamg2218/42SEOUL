/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:32:21 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/11 21:22:54 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "get_next_line.h"
# include "../utils/utils.h"
# include "../mlx_opengl/mlx.h"
# include <stdio.h>
# include <string.h>

typedef struct		s_coord
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	int				stepx;
	int				stepy;
	int				side;
}					t_coord;

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				**buff;
}					t_img;

typedef struct		s_sprite
{
	int				texture;
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_param
{
	void			*mlx;
	void			*win;
	t_coord			coord;
	t_img			img;
	t_sprite		*sprite;
	int				save;
	int				x_render;
	int				y_render;
	int				*mapwidth;
	int				mapheight;
	unsigned int	f_color;
	unsigned int	c_color;
}					t_param;

typedef struct		s_node
{
	int				row;
	int				col;
	struct s_node	*next;
}					t_node;

typedef struct		s_graph
{
	int				count;
	int				height;
	int				**visited;
	t_node			**node;
}					t_graph;

//map.c
int					error(t_param *param, int n);
int					exit_game(t_param *param);
int					parse_map(char *file, t_param *param);
void				set_coord(t_param *param, int row, int col, char dir);
void				put_coord(t_param *param, int dir_x, int dir_y);

//parsing_map.c
int					row_malloc(t_param *param);
int					row_count(char *file, t_param *param);
int					col_malloc(int col, char *linem, t_param *param);
int					read_map(char *file, t_param *param);
int					put_map(int row, t_param *param, char *line);

//parsing_sprite.c
int					count_sprite(t_param *param);
int					read_sprite(t_param *param);
int					write_sprite(t_param *param);

//parsing_cub.c
int					parse_r(t_param *param, char *line);
int					parse_f(t_param *param, char *line);
int					parse_c(t_param *param, char *line);
int					parse_wall(t_param *param, char *line);
int					parse(int *row, t_param *param, char *line);

//xpm.c
int					read_xpm(t_param *param);
void				xpm_to_image(int i, char *file, t_param *param);

//dfs.c
int					set_edge_row(t_param *param, t_graph *graph, int *rc);
int					set_edge_col(t_param *param, t_graph *graph, int *rc);
int					set_edge(t_param *param, t_graph *graph);
int					dfs(t_param *param, t_graph *graph, int *start, int *end);
int					add_edge(t_param *param, t_graph *graph, int *rc, int *xy);

//checking_map.c
int					check_map(t_param *param);
int					find_start(t_param *param, int *start);
int					malloc_graph(t_param *param, t_graph *graph);
void				clear_graph(t_graph *graph);
t_graph				*create_graph(t_param *param);

#endif
