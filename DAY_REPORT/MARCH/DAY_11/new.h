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

void    ft_lstclear(t_list **lst);
void    *ft_memset(void *ptr, int value, unsigned int num);
t_list  *ft_lstnew(void);
void    ft_lstadd_back(t_list **lst, t_list *n);
int     ft_start_check(t_list *start);
void    ft_cpy_line(char *line, t_list *start, int i);
int     ft_find_i(t_list *start, int i);
void	ft_memcpy(t_list *start, unsigned int num);

#endif