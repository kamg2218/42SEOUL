#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
  void            *content;
  struct s_list   *next;
}                 t_list;

int     BUFFER_SIZE = 100;
//1
void    ft_lstclear(t_list **lst)
{
    t_list  *L;
    t_list  *front;

    L = *lst;
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
    t_list  *n;

    n = (t_list *)malloc(sizeof(t_list));
    n->content = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (n->content == NULL || n == NULL)
        return (0);
    ft_memset(n->content, 0, BUFFER_SIZE);
    n->next = NULL;
    return (n);
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
  while (*(char *)(lst->content))
  {
    j = 0;
    while (*((char *)(lst->content) + j))
    {
      if (*((char *)(lst->content) + j) == -1)
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

int     get_next_line(int fd, char **line)
{
  int             i;
  int             re;
  t_list          *r_lst;
  t_list          *lst;
  static t_list   *start;

  ft_lstadd_back(&start, ft_lstnew());
  if ((i = ft_start_check(start)) != -1)
  {
    *line = (char *)malloc(sizeof(char) * (i + 1));
    if (*line == NULL)
      return (-1);
    ft_cpy_line(*line, start, i);
    ft_memcpy(start, i);
    return (ft_start_check(start) ? 1 : 0);
  }
  r_lst = ft_lstnew();
  re = read(fd, r_lst->content, BUFFER_SIZE);
  if (0 <= re && re < BUFFER_SIZE)
  {
    *((char *)(r_lst->content) + re) = -1;
    re++;
  }
  lst = start;
  while (lst->next)
    lst = lst->next;
  ft_cpy_line((char *)(lst->content), r_lst, re);
  i = ft_start_check(start);
  *line = (char *)malloc(sizeof(char) * (i + 1));
  if (*line == NULL)
    return (-1);
  ft_cpy_line(*line, start, i);
  ft_memcpy(start, i);
  printf("i = %d\n", ft_start_check(start));
  return (ft_start_check(start) ? 1 : 0);
}

int main() 
{
	int     i;
	char    c;
	char    *line;
  int     fd = open("test.txt", O_RDWR, 0644);
  
	if (fd == -1)
	  return (-1);
//    while ((i = get_next_line(fd, &line)) == 1)
//        printf("i = %d, line = %s\n", i, line);
  BUFFER_SIZE = 10;
  for (int j = 0; j < 3; j++)
    printf("i = %d, line = !%s!\n", get_next_line(fd, &line), line);

  printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
  close(fd);
  return 0;
}