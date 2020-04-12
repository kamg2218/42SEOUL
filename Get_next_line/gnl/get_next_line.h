/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:28:16 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/13 01:28:19 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_find_i(t_list *start, int i);
int				get_next_line(int fd, char **line);
int				ft_read_file(int fd, t_list *start);
void			ft_add_null(t_list *lst, unsigned int i);
void			ft_memcpy(t_list *start, unsigned int num);

int				ft_start_check(t_list *start);
void			ft_lstclear(t_list **lst);
void			ft_lstadd_back(t_list **lst, t_list *n);
void			ft_cpy_line(char *line, t_list *start, int i);
t_list			*ft_lstnew(void);

#endif
