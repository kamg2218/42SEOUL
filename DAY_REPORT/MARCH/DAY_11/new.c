#include "new.h"

int     get_next_line(int fd, char **line)
{
  int             i;
  int             re;
  t_list          *r_lst;
  t_list          *lst;
  static t_list   *start;

  if (!start)
    ft_lstadd_back(&start, ft_lstnew());
  if ((i = ft_start_check(start)) != -1)
  {
    *line = (char *)malloc(sizeof(char) * (i + 1));
    if (*line == NULL)
      return (-1);
    ft_cpy_line(*line, start, i);
    ft_memcpy(start, i);
    return (*(char *)(start->content) == -1 ? 0 : 1);
  }
  while (1)
  {
    ft_lstadd_back(&start, ft_lstnew());
    r_lst = ft_lstnew();
    re = read(fd, r_lst->content, BUFFER_SIZE);
    if (re == -1)
      return (-1);
    if (0 <= re && re < BUFFER_SIZE)
    {
      *((char *)(r_lst->content) + re) = -1;
      re++;
      break ;
    }
    else if (ft_start_check(r_lst) == -1)
    {
      lst = start;
      while (lst->next)
        lst = lst->next;
      ft_cpy_line((char *)(lst->content), r_lst, re);
      //ft_lstadd_back(&start, ft_lstnew());
      free(r_lst);    
      continue  ;      
    }
    else
      break ;
  }
  lst = start;
  while (lst->next)
    lst = lst->next;
  ft_cpy_line((char *)(lst->content), r_lst, re);
  i = ft_start_check(start);
  printf("i = %d\n", i);
  *line = (char *)malloc(sizeof(char) * (i + 1));
  if (*line == NULL)
    return (-1);
  ft_cpy_line(*line, start, i);
  ft_memcpy(start, i);
  printf("start = %s\n", start->content);
  return (*(char *)(start->content) == -1 ? 0 : 1);
}

int main() 
{
	int     i;
	char    c;
	char    *line;
  int     fd = open("test.txt", O_RDWR);
  
	if (fd == -1)
	  return (-1);

  BUFFER_SIZE = 100;
/*
  for (int j = 0; j < 7; j++){
    printf("i = %d, line = !%s!\n", get_next_line(fd, &line), line);
    printf("-------------------------\n");
  }
*/

  while ((i = get_next_line(fd, &line)) == 1)
    printf("i = %d, line = %s\n---------------------\n", i, line);
  printf("i = %d, line = %s\n---------------------\n", i, line);

  printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
  free(line);
  close(fd);
  return 0;
}