#include "get_next_line.h"

int     ft_check(char *str)
{
  int   i;

  i = 0;
  if (str[i] == -1 || str == NULL)
    return (0);
  while (i < BUFFER_SIZE + 1)
  {
    if (str[i] == '\n' || str[i] == -1)
      return (i);
    i++;
  }
  return (-1);
}

void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned int	i;
  unsigned int  j;

	i = 0;
  j = 0;
  while (*((char *)dest + j))
    j++;
	if (!n)
    *((char *)dest + j) = 0;
  while (i < n)
	{
		*((char *)dest + i + j) = *((char *)src + i);
		if (*((char *)src + i) == c || *((char *)src + i) == EOF)
      {
          *((char *)dest + i + j) = 0;
		      return ((char *)dest + i + j + 1);
      }
    i++;
	}
	return  (0);
}

void    ft_cpyeof(t_list *lst, int i)
{
  int   count;

  while (i > BUFFER_SIZE)
  {
    lst = lst->next;
    i -= BUFFER_SIZE;
  }
  *(((char *)(lst->content)) + i) = -1;
}

t_list  *ft_new_start(t_list *start, int i)
{
  int     j;
  t_list  n_start;
  t_list  *n;

  n = (t_list *)malloc(sizeof(t_list));
  if (n == NULL)
    return (0);
  if (*(((char *)(start->content)) + i) == -1)
  {
    n->content = NULL;
    ft_lstclear(n);
    return (n);
  }
  else if (*(((char *)(start->content)) + i) == '\n')
    i++;
  j = 0;
  while (j < BUFFER_SIZE)
  {
    while (i + j > BUFFER_SIZE)
    {
      start = start->next;
      i -= BUFFER_SIZE;
    }
    if (*(((char *)(start->content)) + i + j) == -1)
      break ;
    j++;
  }
  n->content = (char *)malloc(sizeof(char) * (j + 1));
  ft_memccpy(n->content, (char *)(start->content) + i, -1, j);
  *((char *)(n->content) + j) = -1;
  return (n);
}

int     get_next_line(int fd, char **line)
{
  int     i;
  int     j;
  int     re;
  t_list  n;
  t_list  **lst;
  static t_list  *start;

  ft_lstadd_back(&start, ft_lstnew());
  lst = &start;
  n.content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if (n.content == NULL)
    return (-1);
  if((i = ft_check(start->content)) != -1)
  {
    *line = (char *)malloc(sizeof(char) * (i + 1));
    if (*line == NULL)
      return (-1);
    ft_cpyline(line, start, i);
    start = ft_new_start(start, i);
    if (start->content)
      j = ft_check(start->content);
    else
      j = -2;
    if (j == -2)
      return (0);
    else if (j != -1)
      return (1);
  }
  if (i == -1)
    i = 0;
  while ((re = read(fd, n.content, BUFFER_SIZE)))
  {
    ft_lstadd_back(&start, ft_lstnew());
    if (re == -1)
      return (-1);
    else if (re == 0)
      return (0);
    ft_lstadd_back(&start, ft_lstnew());
    while ((*lst)->next)
      *lst = (*lst)->next;
    ft_memccpy((*lst)->content, n.content, -1, re);
    if (re < BUFFER_SIZE)
      ft_cpyeof(start, re);
    if ((j = ft_check((*lst)->content)) != -1)
    {
      i += j;
      break;
    }
    else
      i += BUFFER_SIZE;
  }
  *line = (char *)malloc(sizeof(char) * (i + 1));
  if (*line == NULL)
    return (-1);
  ft_cpyline(line, start, i);
  start = ft_new_start(start, i);
  if (re > 0)
    return (1);
  else
    return (0);
}

int main() 
{
	int     i;
	char    c;
	char    *line;
  int     fd = open("test.txt", O_RDWR, 0644);
  
	if (fd == -1)
	  return (-1);
  while ((i = get_next_line(fd, &line)) == 1)
    printf("i = %d, line = %s\n", i, line);
/*
  for (int j = 0; j < 13; j++){
    i = get_next_line(fd, &line);
    printf("i = %d, line = !%s!\n", i, line);
  }
*/
  printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
  close(fd);
  return 0;
}