#include "new.h"

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
void    *ft_memset(void *ptr, int value, unsigned int num)
{
  unsigned int  i;

  i = 0;
  while (i < num)
  {
    *((unsigned char *)ptr + i) = value;
    i++;
  }
  return (ptr);
}
//3
t_list  *ft_lstnew(void)
{
    t_list  *lst;

    lst = (t_list *)malloc(sizeof(t_list));
    lst->content = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (lst->content == NULL || lst == NULL)
        return (0);
    ft_memset(lst->content, 0, BUFFER_SIZE);
    lst->next = NULL;
    return (lst);
}
//4
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
//5
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
//6
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
//7
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
//8
void	ft_memcpy(t_list *start, unsigned int num)
{
	unsigned int	count;
  unsigned int  i;
	t_list        *lst;
  char          ch;

	lst = start;
  count = num;
  if ((ch = ft_find_i(lst, count)) == -1)
  {
    *(char *)(start->content) = -1;
    return  ;
  }
  i = -1;
  while ((ch = ft_find_i(start, ++count)) != 0)
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
  if (++i >= BUFFER_SIZE)
  {
    lst = lst->next;
    *((char *)(lst->content)) = 0;  
  }
  else
    *((char *)(lst->content) + i) = 0;
  ft_lstclear(&(lst->next));
}