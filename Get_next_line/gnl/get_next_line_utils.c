/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:28:42 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/15 17:00:39 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_lstclear(t_list **lst, int fd)
{
	t_list			*l;
	t_list			*front;

	l = *lst;
	if (!l)
		return ;
	while (l->file_num != fd)
		l = l->next;
	while (l->next->file_num == fd)
	{
		front = l;
		l = l->next;
		if (front->content)
			free(front->content);
		free(front);
	}
	if (front->content)
		free(front->content);
	free(l);
	*lst = NULL;
}

t_list		*ft_lstnew(int fd)
{
	t_list			*lst;
	unsigned int	i;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->content = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (lst->content == NULL || lst == NULL)
	{
		if (lst)
			free(lst);
		return (0);
	}
	lst->file_num = fd;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		*((unsigned char *)(lst->content) + i) = 0;
		i++;
	}
	lst->next = NULL;
	return (lst);
}

void		ft_lstadd_back(t_list **lst, t_list *n, int fd)
{
	t_list			*l;

	l = *lst;
	if (!n)
		return ;
	else if (!l)
	{
		*lst = n;
		return ;
	}
	while (l->file_num != fd)
		l = l->next;
	while (l->next->file_num == fd)
		l = l->next;
	n->next = l->next;
	l->next = n;
}

int			ft_start_check(t_list *start, int fd)
{
	int				i;
	int				j;
	t_list			*lst;

	i = 0;
	lst = start;
	while (lst->file_num != fd)
		lst = lst->next;
	while (lst->file_num == fd)
	{
		j = 0;
		while (*((char *)(lst->content) + j))
		{
			if (*((char *)(lst->content) + j) == -1
					|| *((char *)(lst->content) + j) == '\n')
				return (i);
			i++;
			j++;
		}
		lst = lst->next;
	}
	return (-1);
}

void		ft_cpy_line(char *line, t_list *start, int i, int fd)
{
	int				count;
	int				s_count;
	t_list			*lst;

	count = 0;
	s_count = 0;
	lst = start;
	while (lst->file_num != fd)
		lst = lst->next;
	while (count < i)
	{
		if (*((char *)(lst->content) + s_count) == 0)
		{
			lst = lst->next;
			s_count = 0;
			if (lst->file_num != fd)
				return ;
		}
		*(line + count) = *((char *)(lst->content) + s_count);
		count++;
		s_count++;
	}
	*(line + count) = 0;
}
