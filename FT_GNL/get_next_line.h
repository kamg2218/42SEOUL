/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:15:43 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/29 20:12:32 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_start_check(t_list *start);
int					ft_find_i(t_list *start, int i);
int					get_next_line(int fd, char **line);
int					ft_read_file(int fd, t_list *start);
int					ft_first_processing(int fd, char **line, t_list **start);
void				ft_lstclear(t_list **lst);
void				ft_lstadd_back(t_list **lst, t_list *n);
void				ft_memcpy(t_list *start, int num);
void				ft_cpy_line(char *line, t_list *start, int i);
t_list				*ft_lstnew(void);

#endif
