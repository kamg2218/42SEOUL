/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:43:36 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/28 00:22:42 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list				*find_list(t_list *start)
{
	t_list			*lst;

	lst = start;
	while (lst->next)
		lst = lst->next;
	if (*((char *)lst->content))
	{
		ft_lstadd_back(&lst, ft_lstnew(BUFFER_SIZE));
		lst = lst->next;
	}
	return (lst);
}

int					ft_read_file(int fd, t_list *start)
{
	int				re;
	t_list			*lst;

	lst = find_list(start);
	re = read(fd, lst->content, BUFFER_SIZE);
	if (fd == 0 && re == 0)
	{
		if (start == lst)
			kill(0, SIGTERM);
		re += ft_read_file(fd, start);
	}
	if (re == -1 || BUFFER_SIZE <= 0)
		return (-1);
	if (re < BUFFER_SIZE)
	{
		*((char *)(lst->content) + re) = -1;
		re++;
	}
	if (ft_start_check(start) == -1)
		re += ft_read_file(fd, start);
	return (re);
}

int					ft_first_processing(int fd, char **line, t_list **start)
{
	int				i;

	if (fd < 0 || line == NULL)
	{
		ft_lstclear(start);
		return (-1);
	}
	else if (*start == NULL)
		ft_lstadd_back(start, ft_lstnew(BUFFER_SIZE));
	if ((i = ft_start_check(*start)) == -1)
	{
		if (ft_read_file(fd, *start) <= 0)
		{
			ft_lstclear(start);
			return (-1);
		}
		i = ft_start_check(*start);
	}
	return (i);
}

int					get_next_line(int fd, char **line, t_list **start)
{
	int				i;
	int				next;

	if ((i = ft_first_processing(fd, line, start)) == -1)
		return (-1);
	if ((*line = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
	{
		ft_lstclear(start);
		return (-1);
	}
	next = ft_find_i(*start, i);
	ft_cpy_line(*line, *start, i);
	ft_lst_memcpy(*start, i);
	return (1);
}
