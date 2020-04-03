#include "get_next_line.h"

int     ft_malloc(char **line, int i)
{
  int   j;

  j = 0;
  while (line[j])
    j++;
  line[j] = (char *)malloc(sizeof(char) * (i + 1));
  if (line[j] == NULL)
    return (0);
  else
    return (j); 
}

int     ft_check(char *str)
{
  int   i;

  i = 0;
  while (i < BUFSIZ + 1)
  {
    if (str[i] == '\n' || str[i] == EOF)
      return (i);
    i++;
  }
  if (i > BUFSIZ)
    return (-1);
  else
    return (i);
}

void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned int	i;
  unsigned int  j;

	i = 0;
  j = 0;
  while (*((char *)dest + j))
    j++;
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

  while (i > BUFSIZ)
  {
    lst = lst->next;
    i -= BUFSIZ;
  }
  *(((char *)(lst->content)) + i) = -1;
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
  if((i = ft_check((*lst)->content)) != -1)
  {
    printf("i = %d\n", i);
    if (!(j = ft_malloc(line, i)))
      return (-1);
    ft_cpyline(line, start, i, j);
    start = ft_delcont(start, i);
    printf("%s\n", start->content);
    return ((*((char *)((*lst)->content)) == -1) ? 0 : 1);
  }
  if (i == -1)
    i = 0;
  n.content = (char *)malloc(sizeof(char) * (BUFSIZ + 1));
  if (n.content == NULL)
    return (-1);
  while ((re = read(fd, n.content, BUFSIZ)))
  {
    if (re == -1)
      return (-1);
    else if (re == 0)
      return (0);
    ft_lstadd_back(&start, ft_lstnew());
    while ((*lst)->next)
      *lst = (*lst)->next;
    ft_memccpy((*lst)->content, n.content, -1, re);
    ft_cpyeof(start, re);
    if ((j = ft_check((*lst)->content)) != -1)
    {
      i += j;
      break;
    }
    else
      i += BUFSIZ;
  }
  if (!(j = ft_malloc(line, i)))
    return (-1);
  ft_cpyline(line, start, i, j);
  start = ft_delcont(start, i);
  if (re)
    return (1);
  else
    return (0);
}

int main() 
{
	int     i;
	int     j;
  int     k;
	int     count;
	char    buf;
	char    buf_str[10];
	char    **line;
  int     fd = open("test.txt", O_RDWR, 0644);
  
	if (fd == -1)
	  return (-1);
  line = (char **)malloc(sizeof(char *) * 100);
  if (line == NULL)
    return (0);
	i = 0;
  k = 0;
	while (1)
  {
    read(fd, buf_str + i, 1);
    if (buf_str[i] == '\n')
    {
      line[k] = (char *)malloc(sizeof(char) * (i + 1));
      if (line[k] == NULL)
        return (0);
      for (int j = 0; j < i; j++)
        line[k][j] = buf_str[j];
      line[k][j] = 0;
      break ;
    }
    i++;
  }
  /*
  printf("line[0] = %s\n", line[0]);
  printf("%d\n", get_next_line(fd, line));
  printf("%d\n", get_next_line(fd, line));
  printf("%d\n", get_next_line(fd, line));
  printf("%d\n", get_next_line(fd, line));
  printf("%d\n", get_next_line(fd, line));
  printf("%d\n", get_next_line(fd, line));
  printf("%d\n", get_next_line(fd, line));
*/
  while (get_next_line(fd, line))
  k = 0;
  while (line[k])
  {
    printf("k = %d, !%s!\n", k, line[k]);
    k++;
  }
  close(fd);
  free(line);
  return 0;
}