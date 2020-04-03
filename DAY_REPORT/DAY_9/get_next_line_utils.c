#include "get_next_line.h"

void    ft_lstclear(t_list *lst)
{
  t_list  **L;
  t_list  **front;

  L = &lst;
  if (!(*L))
    return  ;
  while ((*L)->next)
  {
    *front = *L;
    *L = (*L)->next;
    free(*front);
  }
  free(*L);
}

t_list  *ft_lstnew(void)
{
  t_list  *new;

  new = (t_list *)malloc(sizeof(t_list));
  if (new == NULL)
    return (0);
  new->content = (char *)malloc(sizeof(char) * (BUFSIZ + 1));
  if (new->content == NULL)
    return (0);
  new->next = NULL;
  return (new);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
  t_list  *L;

  L = *lst;
	if (!new)
		return	;
	else if (!L)
	{
		*lst = new;
		return	;
	}
  while (L->next)
  	L = L->next;
  L->next = new;
  new->next = NULL;
}

void    ft_cpyline(char **line, t_list *start, int i, int j)
{
  t_list  **lst;

  while (1)
  {
    if (i > BUFSIZ)
    {
      lst = &start;
      start = start->next;
      free(*lst);
      i -= BUFSIZ;
      ft_memccpy(line[j], start->content, '\n', BUFSIZ);
    }
    else
    {
      ft_memccpy(line[j], start->content, '\n', i);
      break;
    }
  }
}

t_list    *ft_delcont(t_list *start, int i)
{
  int     n_count;
  t_list  **lst;
  t_list  **n_lst;

  n_count = -1;
  lst = &start;
  n_lst = &start;
  while (i > BUFSIZ)
  {
    (*lst) = (*lst)->next;
    i -= BUFSIZ;
  }
  while (*((char *)((*lst)->content) + ++i) != -1)
  {
    n_count++;
    if (i > BUFSIZ)
    {
      *lst = (*lst)->next;
      i = 0;
    }
    if (n_count > BUFSIZ)
    {
      *n_lst = (*n_lst)->next;
      n_count = 0;
    }
    *((char *)((*n_lst)->content) + n_count) = *((char *)((*lst)->content) + i);
  }
  n_count++;
  while (*((char *)((*n_lst)->content) + n_count) != -1)
  {
    *((char *)((*n_lst)->content) + n_count) = -1;
    n_count++;
  }
  ft_lstclear((*n_lst)->next);
  (*n_lst)->next = NULL;
  return (start);
}