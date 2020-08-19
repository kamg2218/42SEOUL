/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:18:29 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:18:31 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int					parse_r(int *max_row, t_param *param, char *line)
{
	int				i;
	int				j;
	int				len;
	int				num;

	i = 0;
	j = 0;
	num = 0;
	len = ft_strlen(line);
	while (++i < len)
	{
		if (ft_isalnum(line[i]) == 4)
		{
			i += char_to_num(line + i, &num);
			if (!j)
				param->x_render = num;
			else
				param->y_render = num;
			j = !j;
		}
	}
	if (!param->x_render || !param->y_render)
		return (0);
	*max_row -= 1;
	return (1);
}

int					parse_f(int *max_row, t_param *param, char *line)
{
	int				i;
	int				len;
	int				num;
	unsigned int	hexa;

	i = 0;
	num = 0;
	hexa = 0;
	len = ft_strlen(line);
	while (++i < len)
	{
		if (ft_isalnum(line[i]) == 4)
		{
			i += char_to_num(line + i, &num);
			hexa = hexa * 256 + (unsigned int)num;
		}
	}
	*max_row -= 1;
	param->f_color = hexa;
	return (1);
}

int					parse_c(int *max_row, t_param *param, char *line)
{
	int				i;
	int				len;
	int				num;
	unsigned int	hexa;

	i = 0;
	num = 0;
	hexa = 0;
	len = ft_strlen(line);
	while (++i < len)
	{
		if (ft_isalnum(line[i]) == 4)
		{
			i += char_to_num(line + i, &num);
			hexa = hexa * 256 + (unsigned int)num;
		}
	}
	*max_row -= 1;
	param->c_color = hexa;
	return (1);
}

int					parse_wall(int *max_row, t_param *param, char *line)
{
	if (line[0] == 'E' && line[1] == 'A')
		xpm_to_image(0, &line[3], param);
	else if (line[0] == 'W' && line[1] == 'E')
		xpm_to_image(1, &line[3], param);
	else if (line[0] == 'S' && line[1] == 'O')
		xpm_to_image(2, &line[3], param);
	else if (line[0] == 'N' && line[1] == 'O')
		xpm_to_image(3, &line[3], param);
	*max_row -= 1;
	return (1);
}

int					parse(int *row, int *max_row, t_param *param, char *line)
{
	if (line == NULL)
		return (0);
	else if ((line[0] == 'N' && line[1] == 'O')
			|| (line[0] == 'S' && line[1] == 'O')
			|| (line[0] == 'W' && line[1] == 'E')
			|| (line[0] == 'E' && line[1] == 'A'))
		parse_wall(max_row, param, line);
	else if (ft_isalnum(line[0]) == 2)
		return (0);
	else if (num_in_line(line))
	{
		if (!(put_map(*row, *max_row, param, line)))
			return (0);
		*row += 1;
	}
	else
		*max_row -= 1;
	return (1);
}
