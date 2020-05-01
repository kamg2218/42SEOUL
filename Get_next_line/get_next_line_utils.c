/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:03:29 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/29 01:06:59 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*l;
	t_list	*front;

	l = *lst;
	if (!l)
		return ;
	while (l)
	{
		front = l;
		l = l->next;
		if (front->content)
			free(front->content);
		free(front);
	}
	*lst = NULL;
}

t_list	*ft_lstnew(void)
{
	int				i;
	t_list			*lst;

	lst = (t_list *)malloc(sizeof(t_list));
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
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *n)
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
	while (l->next)
		l = l->next;
	l->next = n;
	n->next = NULL;
}

int		ft_start_check(t_list *start)
{
	int				i;
	int				j;

	i = 0;
	while (start)
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

void	ft_cpy_line(char *line, t_list *start, int i)
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
