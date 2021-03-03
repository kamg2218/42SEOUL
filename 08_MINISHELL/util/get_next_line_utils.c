/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:03:29 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/24 01:11:09 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_start_check(t_list *start)
{
	int				i;
	int				j;

	i = 0;
	while (start)
	{
		j = -1;
		while (++j < BUFFER_SIZE)
		{
			if (*((char *)(start->content) + j) == 0)
			{
				j = BUFFER_SIZE;
				continue ;
			}
			else if ((*((char *)(start->content) + j) == -1)
				|| (*((char *)(start->content) + j) == '\n'))
				return (i);
			i++;
		}
		start = start->next;
	}
	return (-1);
}

void				ft_cpy_line(char *line, t_list *start, int i)
{
	int				count;
	int				s_count;
	t_list			*lst;

	count = 0;
	s_count = 0;
	lst = start;
	while (count < i)
	{
		if (s_count >= BUFFER_SIZE
				|| *((char *)lst->content + s_count) == 0)
		{
			lst = lst->next;
			s_count = 0;
		}
		*(line + count) = *((char *)(lst->content) + s_count);
		count++;
		s_count++;
	}
	*(line + count) = 0;
}

int					ft_find_i(t_list *start, int i)
{
	int				count;
	int				l_count;
	int				result;
	t_list			*lst;

	count = 0;
	l_count = 0;
	lst = start;
	while (count <= i && lst)
	{
		if (l_count == BUFFER_SIZE
				|| !(result = *((char *)(lst->content) + l_count)))
		{
			lst = lst->next;
			l_count = -1;
			count--;
		}
		count++;
		l_count++;
	}
	if (!lst && count <= i)
		result = -2;
	return (result);
}
