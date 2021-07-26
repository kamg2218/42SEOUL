/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:43:36 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/20 20:44:59 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	do_read(t_g_list *lst, int fd)
{
	int		re;

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
	return (re);
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
	re = do_read(lst, fd);
	if (re == -1)
		return (-1);
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

void	do_gnl(t_g_list *start, int i, int fd)
{
	t_g_list	*lst;

	lst = ft_mem_cpy(start, i, fd);
	while (lst && lst->num == fd)
	{
		*(char *)(lst->content) = 0;
		lst = lst->next;
	}
}

int	get_next_line(int fd, char **line)
{
	int				i;
	int				next;
	static t_g_list	*start;

	i = ft_first_processing(fd, line, &start);
	if (i == -1)
	{
		while (start)
			ft_lst_clear(&start, start->num);
		return (-1);
	}
	next = ft_find_i(start, i, fd);
	ft_cpy_line(*line, start, i, fd);
	do_gnl(start, i, fd);
	if (next != '\n')
	{
		ft_lst_clear(&start, fd);
		return (0);
	}
	return (1);
}
