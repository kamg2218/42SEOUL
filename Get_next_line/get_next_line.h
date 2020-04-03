#ifndef NEW_H
# define NEW_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
  void            *content;
  struct s_list   *next;
}                 t_list;

int     BUFFER_SIZE;

//get_next_line
int     ft_find_i(t_list *start, int i);
int     get_next_line(int fd, char **line);
void    ft_add_null(t_list *lst, unsigned int i);
void	  ft_memcpy(t_list *start, unsigned int num);
t_list  *ft_read_file(int fd, t_list *start);

//get_next_line_utils
int     ft_start_check(t_list *start);
void    ft_lstclear(t_list **lst);
void    ft_lstadd_back(t_list **lst, t_list *n);
void    ft_cpy_line(char *line, t_list *start, int i);
t_list  *ft_lstnew(void);

#endif