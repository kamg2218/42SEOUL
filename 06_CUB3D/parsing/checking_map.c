/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:17:57 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:17:59 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

extern int		**g_map;

int				malloc_graph(t_param *param, t_graph *graph)
{
	int			row;
	int			col;
	int			count;
	int			*width;

	row = -1;
	count = 0;
	width = param->mapwidth;
	while (++row < param->mapheight)
	{
		if (!(graph->visited[row] = malloc(sizeof(int) * (width[row] + 1))))
			return (error(param, 5));
		col = -1;
		while (++col < width[row])
		{
			graph->node[count + col] = 0;
			graph->visited[row][col] = 0;
		}
		graph->visited[row][col] = 0;
		count += width[row];
	}
	graph->visited[row] = 0;
	graph->node[count] = 0;
	return (1);
}

t_graph			*create_graph(t_param *param)
{
	int			row;
	int			col;
	int			count;
	t_graph		*graph;

	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
		return (0);
	graph->height = param->mapheight;
	row = -1;
	count = 0;
	while (++row < param->mapheight)
		count += param->mapwidth[row];
	graph->count = count;
	if (!(graph->node = (t_node **)malloc(sizeof(t_node *) * (count + 1))))
		return (0);
	if (!(graph->visited = malloc(sizeof(int *) * (param->mapheight + 1))))
		return (0);
	if (!(malloc_graph(param, graph)))
		return (0);
	return (graph);
}

void			clear_graph(t_graph *graph)
{
	int			row;
	t_node		*new;
	t_node		*tmp;

	row = -1;
	while (++row < graph->height)
		free(graph->visited[row]);
	free(graph->visited);
	row = -1;
	while (++row < graph->count)
	{
		new = graph->node[row];
		while (new != NULL)
		{
			tmp = new;
			new = new->next;
			free(tmp);
		}
	}
	free(graph->node);
}

int				find_start(t_param *param, int *start)
{
	int			row;
	int			col;

	row = -1;
	while (++row < param->mapheight)
	{
		col = -1;
		while (++col < param->mapwidth[row])
		{
			if (g_map[row][col] == 1)
			{
				start[0] = row;
				start[1] = col;
				return (1);
			}
		}
	}
	return (0);
}

int				check_map(t_param *param)
{
	int			count;
	int			result;
	int			start[2];
	int			end[2];
	t_graph		*graph;

	if (!(graph = create_graph(param)))
		return (error(param, 5));
	if (!(set_edge(param, graph)))
		return (0);
	if (!(find_start(param, start)))
		return (error(param, 2));
	end[0] = start[0];
	end[1] = start[1];
	result = dfs(param, graph, start, end);
	clear_graph(graph);
	return (result);
}
