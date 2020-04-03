#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
  void            *content;
  struct s_list   *next;
}                 t_list;

int     ft_check(char *str);
int     ft_malloc(char **line, int i);
int     get_next_line(int fd, char **line);
void    ft_cpyeof(t_list *lst, int i);
void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n);

//utils
void    ft_lstclear(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_cpyline(char **line, t_list *start, int i, int j);
t_list  *ft_lstnew(void);
t_list  *ft_delcont(t_list *start, int i);

#endif