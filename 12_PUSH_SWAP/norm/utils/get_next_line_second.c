/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_second.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:43:36 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/20 20:44:25 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_g_list	*do_find_i(t_g_list *lst, int i, int *count, int *result)
{
	int		l_count;

	l_count = 0;
	while (*count <= i && lst)
	{
		if (l_count != BUFFER_SIZE)
			*result = *((char *)(lst->content) + l_count);
		if (l_count == BUFFER_SIZE || !(*result))
		{
			lst = lst->next;
			l_count = -1;
			(*count)--;
		}
		(*count)++;
		l_count++;
	}
	return (lst);
}

int	ft_find_i(t_g_list *start, int i, int fd)
{
	int			count;
	int			result;
	t_g_list	*lst;

	count = 0;
	lst = start;
	while (lst && lst->num != fd)
		lst = lst->next;
	lst = do_find_i(lst, i, &count, &result);
	if ((!lst && count <= i) || lst->num != fd)
		result = -2;
	return (result);
}

t_g_list	*do_memcpy(t_g_list *start, int num, int fd)
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
	int			i;
	char		ch;
	t_g_list	*lst;

	lst = do_memcpy(start, num, fd);
	if (lst == NULL)
		return (NULL);
	i = -1;
	ch = 0;
	while (ch != -2)
	{
		ch = ft_find_i(start, ++num, fd);
		if (ch == 0 || ch == -2)
			break ;
		if (!*((char *)(lst->content) + ++i) || i == BUFFER_SIZE)
		{
			lst = lst->next;
			i = 0;
		}
		*((char *)(lst->content) + i) = ch;
	}
	if (++i != BUFFER_SIZE)
		*(char *)(lst->content + i) = 0;
	return (lst->next);
}
