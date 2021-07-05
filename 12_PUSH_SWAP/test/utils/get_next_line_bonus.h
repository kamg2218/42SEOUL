/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:15:43 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 14:58:54 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE	5

typedef struct s_g_list
{
	int				num;
	void			*content;
	struct s_g_list	*next;
}					t_g_list;

int					ft_start_check(t_g_list *start, int fd);
int					ft_find_i(t_g_list *start, int i, int fd);
int					get_next_line(int fd, char **line);
int					ft_read_file(int fd, t_g_list *start);
int					do_first(int fd, char **line, t_g_list **start);
int					ft_first_processing(int fd, char **line, t_g_list **start);
void				ft_lst_clear(t_g_list **lst, int fd);
void				ft_lst_add_back(t_g_list **lst, t_g_list *n, int fd);
void				ft_cpy_line(char *line, t_g_list *start, int i, int fd);
t_g_list			*ft_lst_new(int fd);
t_g_list			*ft_check(t_g_list *start, int num, int fd);
t_g_list			*ft_mem_cpy(t_g_list *start, int num, int fd);

#endif
