/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:15:43 by hyoon             #+#    #+#             */
/*   Updated: 2020/05/01 00:37:04 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	int				num;
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_start_check(t_list *start, int fd);
int					ft_find_i(t_list *start, int i, int fd);
int					get_next_line(int fd, char **line);
int					ft_read_file(int fd, t_list *start);
int					ft_first_processing(int fd, char **line, t_list **start);
void				ft_lstclear(t_list **lst, int fd);
void				ft_lstadd_back(t_list **lst, t_list *n, int fd);
void				ft_cpy_line(char *line, t_list *start, int i, int fd);
t_list				*ft_lstnew(int fd);
t_list				*ft_memcpy(t_list *start, int num, int fd);

#endif
