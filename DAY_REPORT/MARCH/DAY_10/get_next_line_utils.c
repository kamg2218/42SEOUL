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

void    ft_cpyline(char **line, t_list *start, int i)
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
      ft_memccpy(line, start->content, '\n', BUFSIZ);
    }
    else
    {
      ft_memccpy(line, start->content, '\n', i);
      break;
    }
  }
}