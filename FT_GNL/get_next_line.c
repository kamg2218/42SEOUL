/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:43:36 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/29 20:12:20 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_find_i(t_list *start, int i)
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

void	ft_memcpy(t_list *start, int num)
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

int		ft_read_file(int fd, t_list *start)
{
	int				re;
	t_list			*lst;

	lst = start;
	while (lst->next)
		lst = lst->next;
	if (*((char *)lst->content))
	{
		ft_lstadd_back(&lst, ft_lstnew());
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
	if (ft_start_check(start) == -1)
		re += ft_read_file(fd, start);
	return (re);
}

int		ft_first_processing(int fd, char **line, t_list **start)
{
	int				i;

	if (fd < 0 || line == NULL)
	{
		ft_lstclear(start);
		return (-1);
	}
	else if (!*start)
		ft_lstadd_back(start, ft_lstnew());
	if ((i = ft_start_check(*start)) == -1)
	{
		if (ft_read_file(fd, *start) == -1)
		{
			ft_lstclear(start);
			return (-1);
		}
		i = ft_start_check(*start);
	}
	return (i);
}

int		get_next_line(int fd, char **line)
{
	int				i;
	int				next;
	static t_list	*start;

	if ((i = ft_first_processing(fd, line, &start)) == -1)
		return (-1);
	if ((*line = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
	{
		ft_lstclear(&start);
		return (-1);
	}
	next = ft_find_i(start, i);
	ft_cpy_line(*line, start, i);
	ft_memcpy(start, i);
	if (next != '\n')
	{
		ft_lstclear(&start);
		return (0);
	}
	else
		return (1);
}
