/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:03:29 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/24 03:34:48 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list				**get_buffer(void)
{
	static t_list	*content = NULL;

	return (&content);
}

void				ft_lstclear(t_list **lst)
{
	t_list			*l;
	t_list			*front;

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

t_list				*ft_lstnew(int len)
{
	int				i;
	t_list			*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->content = (char *)malloc(sizeof(char) * len);
	if (lst->content == NULL || lst == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		*((unsigned char *)(lst->content) + i) = 0;
		i++;
	}
	lst->next = NULL;
	return (lst);
}

void				ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list			*l;

	l = *lst;
	if (n == NULL)
		return ;
	else if (l == NULL)
	{
		*lst = n;
		return ;
	}
	while (l->next)
		l = l->next;
	l->next = n;
}

void				ft_lst_memcpy(t_list *start, int num)
{
	int				i;
	char			ch;
	t_list			*lst;

	lst = start;
	if (ft_find_i(lst, num) == -1)
	{
		*((char *)lst->content) = -1;
		ft_lstclear(&(lst->next));
		return ;
	}
	i = -1;
	while ((ch = ft_find_i(start, ++num)) && ch != -2)
	{
		if (!*((char *)(lst->content) + ++i) || i == BUFFER_SIZE)
		{
			lst = lst->next;
			i = 0;
		}
		*((char *)(lst->content) + i) = ch;
	}
	if (++i != BUFFER_SIZE)
		*(char *)(lst->content + i) = 0;
	ft_lstclear(&(lst->next));
}
