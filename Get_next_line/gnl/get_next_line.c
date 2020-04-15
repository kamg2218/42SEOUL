/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:17:36 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/15 17:08:40 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_find_i(t_list *start, int i, int fd)
{
	int				count;
	int				l_count;
	int				result;
	t_list			*lst;

	count = 0;
	l_count = 0;
	lst = start;
	while (count <= i && lst->file_num == fd)
	{
		if (!(result = *((char *)(lst->content) + l_count)))
		{
			if (lst->next->file_num == fd)
			{
				lst = lst->next;
				l_count = -1;
				count--;
			}
			else
				return (result);
		}
		count++;
		l_count++;
	}
	return (result);
}

void		ft_memcpy(t_list *start, unsigned int num, int fd)
{
	char			ch;
	unsigned int	i;
	t_list			*lst;

	lst = start;
	if ((ch = ft_find_i(lst, num, fd)) == -1)
	{
		*(char *)(start->content) = -1;
		return ;
	}
	i = -1;
	while ((ch = ft_find_i(start, ++num, fd)) != 0)
	{
		if (*((char *)(lst->content) + ++i) == 0
				|| i == BUFFER_SIZE)
		{
			lst = lst->next;
			i = 0;
		}
		*((char *)(lst->content) + i) = ch;
		if (ch == -1)
			break ;
	}
	ft_add_null(lst, i);
	ft_lstclear(&(lst->next), fd);
}

void		ft_add_null(t_list *lst, unsigned int i)
{
	if (++i >= BUFFER_SIZE)
	{
		lst = lst->next;
		*((char *)(lst->content)) = 0;
	}
	else
		*((char *)(lst->content) + i) = 0;
}

int			ft_read_file(int fd, t_list *start)
{
	int				re;
	t_list			*lst;
	t_list			*r_lst;

	lst = start;
	while (lst->content && lst->next->file_num == fd)
		lst = lst->next;
	if (lst->content)
		ft_lstadd_back(&lst, ft_lstnew(fd), fd);
	r_lst = ft_lstnew(fd);
	re = read(fd, r_lst->content, BUFFER_SIZE);
	if (re == -1)
	{
		free(r_lst);
		return (-1);
	}
	else if (re < BUFFER_SIZE)
	{
		*((char *)(r_lst->content) + re) = -1;
		re++;
	}
	ft_cpy_line((char *)(lst->content), r_lst, re, fd);
	if (ft_start_check(r_lst, fd) == -1)
	{
		free(r_lst);
		ft_read_file(fd, start);
	}
	return (re);
}

int			get_next_line(int fd, char **line)
{
	int				i;
	static t_list	*start;

	if (!start)
		ft_lstadd_back(&start, ft_lstnew(fd), fd);
	if ((i = ft_start_check(start, fd)) != -1)
	{
		*line = (char *)malloc(sizeof(char) * (i + 1));
		if (*line == NULL)
			return (-1);
		ft_cpy_line(*line, start, i, fd);
		ft_memcpy(start, i, fd);
		return (*(char *)(start->content) == -1 ? 0 : 1);
	}
	if (ft_read_file(fd, start) == -1)
	{
		ft_lstclear(&start, fd);
		return (-1);
	}
	i = ft_start_check(start, fd);
	*line = (char *)malloc(sizeof(char) * (i + 1));
	if (*line == NULL)
		return (-1);
	ft_cpy_line(*line, start, i, fd);
	ft_memcpy(start, i, fd);
	return (*(char *)(start->content) == -1 ? 0 : 1);
}
