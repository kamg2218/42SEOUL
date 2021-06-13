/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:03:29 by hyoon             #+#    #+#             */
/*   Updated: 2020/05/01 19:31:47 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lst_clear(t_g_list **lst, int fd)
{
	t_g_list	*l;
	t_g_list	*front;
	t_g_list	*first;

	l = *lst;
	if (!l)
		return ;
	first = NULL;
	while (l && l->num != fd)
	{
		first = l;
		l = l->next;
	}
	while (l && l->num == fd)
	{
		front = l;
		l = l->next;
		free(front->content);
		free(front);
	}
	if (first)
		first->next = l;
	else
		*lst = l;
}

t_g_list	*ft_lst_new(int fd)
{
	int				i;
	t_g_list			*lst;

	lst = (t_g_list *)malloc(sizeof(t_g_list));
	lst->content = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (lst->content == NULL || lst == NULL)
		return (0);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		*((unsigned char *)(lst->content) + i) = 0;
		i++;
	}
	lst->next = NULL;
	lst->num = fd;
	return (lst);
}

void	ft_lst_add_back(t_g_list **lst, t_g_list *n, int fd)
{
	t_g_list			*l;
	t_g_list			*front;

	l = *lst;
	if (!n)
		return ;
	else if (!l)
	{
		*lst = n;
		return ;
	}
	while (l && l->num != fd)
	{
		front = l;
		l = l->next;
	}
	if (!l)
	{
		front->next = n;
		return ;
	}
	while (l->next && l->next->num == fd)
		l = l->next;
	n->next = l->next;
	l->next = n;
}

int		ft_start_check(t_g_list *start, int fd)
{
	int				i;
	int				j;

	while (start && start->num != fd)
		start = start->next;
	i = 0;
	while (start && start->num == fd)
	{
		j = 0;
		while (j < BUFFER_SIZE)
		{
			if (*((char *)(start->content) + j) == 0)
			{
				j = BUFFER_SIZE;
				continue ;
			}
			else if (*((char *)(start->content) + j) == -1 ||
					*((char *)(start->content) + j) == '\n')
				return (i);
			i++;
			j++;
		}
		start = start->next;
	}
	return (-1);
}

void	ft_cpy_line(char *line, t_g_list *start, int i, int fd)
{
	int				count;
	int				s_count;
	t_g_list			*lst;

	count = 0;
	s_count = 0;
	lst = start;
	while (lst && lst->num != fd)
		lst = lst->next;
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
