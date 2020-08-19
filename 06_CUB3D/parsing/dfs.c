/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:18:04 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:18:05 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

extern int		**g_map;

int				add_edge(t_param *param, t_graph *graph, int *rc, int *xy)
{
	int			row;
	int			count;
	t_node		*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (error(param, 5));
	new->row = xy[0];
	new->col = xy[1];
	new->next = NULL;
	row = -1;
	count = 0;
	while (++row < rc[0])
		count += param->mapwidth[row];
	new->next = graph->node[count + rc[1]];
	graph->node[count + rc[1]] = new;
	return (1);
}

int				set_edge_row(t_param *param, t_graph *graph, int *rc)
{
	int			xy[2];

	if (rc[0] - 1 >= 0
			&& rc[1] < param->mapwidth[rc[0] - 1]
			&& g_map[rc[0] - 1][rc[1]] == 1)
	{
		xy[0] = rc[0] - 1;
		xy[1] = rc[1];
		if (!(add_edge(param, graph, rc, xy)))
			return (0);
	}
	if (rc[0] + 1 < param->mapheight
			&& rc[1] < param->mapwidth[rc[0] + 1]
			&& g_map[rc[0] + 1][rc[1]] == 1)
	{
		xy[0] = rc[0] + 1;
		xy[1] = rc[1];
		if (!(add_edge(param, graph, rc, xy)))
			return (0);
	}
	return (1);
}

int				set_edge_col(t_param *param, t_graph *graph, int *rc)
{
	int			xy[2];

	if (rc[1] - 1 >= 0 && g_map[rc[0]][rc[1] - 1] == 1)
	{
		xy[0] = rc[0];
		xy[1] = rc[1] - 1;
		if (!(add_edge(param, graph, rc, xy)))
			return (0);
	}
	if (rc[1] + 1 < param->mapwidth[rc[0]]
			&& g_map[rc[0]][rc[1] + 1] == 1)
	{
		xy[0] = rc[0];
		xy[1] = rc[1] + 1;
		if (!(add_edge(param, graph, rc, xy)))
			return (0);
	}
	return (1);
}

int				set_edge(t_param *param, t_graph *graph)
{
	int			rc[2];
	int			xy[2];

	rc[0] = -1;
	while (++rc[0] < param->mapheight)
	{
		rc[1] = -1;
		while (++rc[1] < param->mapwidth[rc[0]])
		{
			if (g_map[rc[0]][rc[1]] != 1)
				continue ;
			if (!(set_edge_row(param, graph, rc))
					|| !(set_edge_col(param, graph, rc)))
				return (0);
		}
	}
	return (1);
}

int				dfs(t_param *param, t_graph *graph, int *start, int *end)
{
	int			num;
	int			count;
	t_node		*tmp;

	count = 0;
	num = -1;
	while (++num < start[0])
		count += param->mapwidth[num];
	tmp = graph->node[count + start[1]];
	graph->visited[start[0]][start[1]] = 1;
	while (tmp != NULL)
	{
		start[0] = tmp->row;
		start[1] = tmp->col;
		if (graph->visited[start[0]][start[1]] == 0)
			count += dfs(param, graph, start, end);
		if (start[0] == end[0] && start[1] == end[1])
			return (count);
		tmp = tmp->next;
	}
	return (0);
}
