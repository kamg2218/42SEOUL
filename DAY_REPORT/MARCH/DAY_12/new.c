/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 03:09:00 by marvin            #+#    #+#             */
/*   Updated: 2020/03/13 03:09:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

int     get_next_line(int fd, char **line)
{
  int             i;
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
  if (ft_read_file(fd, start) == -1)
    return (-1);
  i = ft_start_check(start);
  *line = (char *)malloc(sizeof(char) * (i + 1));
  if (*line == NULL)
    return (-1);
  ft_cpy_line(*line, start, i);
  ft_memcpy(start, i);
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