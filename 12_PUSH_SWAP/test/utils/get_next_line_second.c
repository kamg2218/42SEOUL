/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_second.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:43:36 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 18:37:08 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_find_i(t_g_list *start, int i, int fd)
{
	int				count;
	int				l_count;
	int				result;

	count = 0;
	l_count = 0;
	while (start && start->num != fd)
		start = start->next;
	while (count <= i && start)
	{
		if (l_count != BUFFER_SIZE)
			result = *((char *)(start->content) + l_count);
		if (l_count == BUFFER_SIZE || !result)
		{
			start = start->next;
			l_count = -1;
			count--;
		}
		count++;
		l_count++;
	}
	if ((!start && count <= i) || start->num != fd)
		result = -2;
	return (result);
}

t_g_list	*ft_check(t_g_list *start, int num, int fd)
{
	t_g_list	*lst;

	lst = start;
	while (lst && lst->num != fd)
		lst = lst->next;
	if (ft_find_i(lst, num, fd) == -1)
	{
		*((char *)lst->content) = -1;
		return (NULL);
	}
	return (lst);
}

t_g_list	*ft_mem_cpy(t_g_list *start, int num, int fd)
{
	int				i;
	char			ch;
	t_g_list		*lst;

	lst = ft_check(start, num, fd);
	if (lst == NULL)
		return (NULL);
	i = -1;
	ch = ft_find_i(start, ++num, fd);
	while (ch && ch != -2)
	{
		if (!*((char *)(lst->content) + ++i) || i == BUFFER_SIZE)
		{
			lst = lst->next;
			i = 0;
		}
		*((char *)(lst->content) + i) = ch;
		ch = ft_find_i(start, ++num, fd);
	}
	if (++i != BUFFER_SIZE)
		*(char *)(lst->content + i) = 0;
	return (lst->next);
}

int	ft_read_file(int fd, t_g_list *start)
{
	int				re;
	t_g_list		*lst;

	lst = start;
	while (lst && lst->num != fd)
		lst = lst->next;
	while (lst->next && lst->next->num == fd && *(char *)lst->content)
		lst = lst->next;
	if (*((char *)lst->content))
	{
		ft_lst_add_back(&lst, ft_lst_new(fd), fd);
		lst = lst->next;
	}
	re = read(fd, lst->content, BUFFER_SIZE);
	if (re == -1 || BUFFER_SIZE <= 0)
		return (-1);
	else if (re < BUFFER_SIZE)
	{
		*((char *)(lst->content) + re) = -1;
		re++;
	}
	if (ft_start_check(start, fd) == -1)
		re += ft_read_file(fd, start);
	return (re);
}
