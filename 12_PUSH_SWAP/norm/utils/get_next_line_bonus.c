/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:43:36 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/09 15:27:04 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_find_i(t_g_list *start, int i, int fd)
{
	int			count;
	int			l_count;
	int			result;
	t_g_list	*lst;

	count = 0;
	l_count = 0;
	lst = start;
	while (lst && lst->num != fd)
		lst = lst->next;
	while (count <= i && lst)
	{
		if (l_count != BUFFER_SIZE)
			result = *((char *)(lst->content) + l_count);
		if (l_count == BUFFER_SIZE
			|| result == NULL)
		{
			lst = lst->next;
			l_count = -1;
			count--;
		}
		count++;
		l_count++;
	}
	if ((!lst && count <= i) || lst->num != fd)
		result = -2;
	return (result);
}

t_g_list	*ft_mem_cpy(t_g_list *start, int num, int fd)
{
	int			i;
	char		ch;
	t_g_list	*lst;

	lst = start;
	while (lst && lst->num != fd)
		lst = lst->next;
	if (ft_find_i(lst, num, fd) == -1)
	{
		*((char *)lst->content) = -1;
		return (NULL);
	}
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

int	ft_read_file(int fd, t_g_list *start)
{
	int			re;
	t_g_list	*lst;

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
	else if (re == 0 && fd == 0)
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

int	ft_first_processing(int fd, char **line, t_g_list **start)
{
	int			i;
	int			re;
	t_g_list	*lst;

	re = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	lst = *start;
	while (lst && lst->num != fd)
		lst = lst->next;
	if (!lst || *(char *)lst->content)
		ft_lst_add_back(start, ft_lst_new(fd), fd);
	i = ft_start_check(*start, fd);
	if (i == -1)
	{
		if (ft_read_file(fd, *start) == -1)
			return (-1);
		i = ft_start_check(*start, fd);
	}
	*line = (char *)malloc(sizeof(char) * (i + 1));
	if (*line == NULL)
		return (-1);
	return (i);
}

int	get_next_line(int fd, char **line)
{
	int				i;
	int				next;
	static t_g_list	*start;
	t_g_list		*lst;

	i = ft_first_processing(fd, line, &start);
	if (i == -1)
	{
		while (start)
			ft_lst_clear(&start, start->num);
		return (-1);
	}
	next = ft_find_i(start, i, fd);
	ft_cpy_line(*line, start, i, fd);
	lst = ft_mem_cpy(start, i, fd);
	while (lst && lst->num == fd)
	{
		*(char *)(lst->content) = 0;
		lst = lst->next;
	}
	if (next != '\n')
	{
		ft_lst_clear(&start, fd);
		return (0);
	}
	return (1);
}
