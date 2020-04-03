/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 03:09:05 by marvin            #+#    #+#             */
/*   Updated: 2020/03/13 03:09:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_H
# define NEW_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
  void            *content;
  struct s_list   *next;
}                 t_list;

int     BUFFER_SIZE;

int     ft_start_check(t_list *start);
int     ft_find_i(t_list *start, int i);
void    ft_lstclear(t_list **lst);
void    ft_lstadd_back(t_list **lst, t_list *n);
void    ft_add_null(t_list *lst, unsigned int i);
void	  ft_memcpy(t_list *start, unsigned int num);
void    ft_cpy_line(char *line, t_list *start, int i);
t_list  *ft_lstnew(void);
t_list  *ft_read_file(int fd, t_list *start);

#endif