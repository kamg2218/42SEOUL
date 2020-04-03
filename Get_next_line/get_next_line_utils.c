#include "new.h"

//1
void    ft_lstclear(t_list **lst)
{
    t_list  *L;
    t_list  *front;

    L = *lst;
    if (!L)
        return  ;    
    while (L->next)
    {
        front = L;
        L = L->next;
        front->content = NULL;
        free(front);
    }
    free(L);
    *lst = NULL;
}
//2
t_list  *ft_lstnew(void)
{
  t_list  *lst;
  unsigned int  i;
  
  lst = (t_list *)malloc(sizeof(t_list));
  lst->content = (char *)malloc(sizeof(char) * BUFFER_SIZE);
  if (lst->content == NULL || lst == NULL)
    return (0);
  i = 0;
  while (i < BUFFER_SIZE)
  {
    *((unsigned char *)(lst->content) + i) = 0;
    i++;
  }
  lst->next = NULL;
  return (lst);
}
//3
void    ft_lstadd_back(t_list **lst, t_list *n)
{
    t_list  *L;

    L = *lst;
	  if (!n)
		  return	;
	  else if (!L)
	  {
  	  *lst = n;
		  return	;
	  }
    while (L->next)
    	L = L->next;
    L->next = n;
    n->next = NULL;
}
//4
int     ft_start_check(t_list *start)
{
  int     i;
  int     j;
  t_list  *lst;

  i = 0;
  lst = start;
  while (lst)
  {
    j = 0;
    while (*((char *)(lst->content) + j))
    {
      if (*((char *)(lst->content) + j) == -1
        || *((char *)(lst->content) + j) == '\n')
        return (i);
      i++;
      j++;
    }
    lst = lst->next;
  }
  return (-1);
}
//5
void    ft_cpy_line(char *line, t_list *start, int i)
{
  int     count;
  int     s_count;
  t_list  *lst;

  count = 0;
  s_count = 0;
  lst = start;
  while (count < i)
  {
    if (*((char *)(lst->content) + s_count) == 0)
    {
      lst = lst->next;
      s_count = 0;
    }
    *(line + count) = *((char *)(lst->content) + s_count);
    count++;
    s_count++;
  }
  *(line + count) = 0;
}
//6
int     ft_find_i(t_list *start, int i)
{
  int     count;
  int     l_count;
  int     result;    
  t_list  *lst;

  count = 0;
  l_count = 0;
  lst = start;
  while (count <= i && lst)
  {
    if (!(result = *((char *)(lst->content) + l_count)))
    {
      lst = lst->next;
      l_count = -1;
      count--;
    }
    count++;
    l_count++;
  }
  return (result);
}
//7
void	ft_memcpy(t_list *start, unsigned int num)
{
  char          ch;
  unsigned int  i;
	t_list        *lst;

	lst = start;
  if ((ch = ft_find_i(lst, num)) == -1)
  {
    *(char *)(start->content) = -1;
    return  ;
  }
  i = -1;
  while ((ch = ft_find_i(start, ++num)) != 0)
  {
    if (*((char *)(lst->content) + ++i) == 0
      || i == BUFFER_SIZE)
    {
      lst = lst->next;
      i = 0;
    }
    *((char *)(lst->content) + i) = ch;
    if (ch == -1)
      break ;
  }
  ft_add_null(lst, i);
  ft_lstclear(&(lst->next));
}
//8
void  ft_add_null(t_list *lst, unsigned int i)
{
  if (++i >= BUFFER_SIZE)
  {
    lst = lst->next;
    *((char *)(lst->content)) = 0;  
  }
  else
    *((char *)(lst->content) + i) = 0;
}
//9
int   ft_read_file(int fd, t_list *start)
{
  int     re;
  t_list  *lst;
  t_list  *r_lst;

  ft_lstadd_back(&start, ft_lstnew());
  r_lst = ft_lstnew();
  re = read(fd, r_lst->content, BUFFER_SIZE);
  if (re == -1)
    return (-1);
  else if (re < BUFFER_SIZE)
  {
    *((char *)(r_lst->content) + re) = -1;
    re++;
  }
  lst = start;
  while (lst->next)
    lst = lst->next;
  ft_cpy_line((char *)(lst->content), r_lst, re);
  if (ft_start_check(r_lst) == -1)
  {
    free(r_lst);
    ft_read_file(fd, start, re);
  }
  return (re);
}