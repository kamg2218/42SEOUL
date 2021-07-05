/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:43:36 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 15:05:25 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_first_processing(int fd, char **line, t_g_list **start)
{
	int				i;
	int				re;
	t_g_list		*lst;

	re = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	lst = *start;
	while (lst && lst->num != fd)
		lst = lst->next;
	printf("start = %p\n", start);
	printf("*start = %p\n", *start);
	printf("lst = %p\n", lst);
	if (!lst || *(char *)lst->content)
		ft_lst_add_back(start, ft_lst_new(fd), fd);
	printf("lst = %p\n", lst);
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

int	do_first(int fd, char **line, t_g_list **start)
{
	int		i;

	i = ft_first_processing(fd, line, start);
	if (i == -1)
	{
		while (*start)
			ft_lst_clear(start, (*start)->num);
		return (-1);
	}
	return (i);
}

int	get_next_line(int fd, char **line)
{
	int				i;
	int				next;
	static t_g_list	*start;
	t_g_list		*lst;

	i = do_first(fd, line, &start);
	if (i == -1)
		return (-1);
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
