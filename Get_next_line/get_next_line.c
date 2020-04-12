#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				i;
	t_list			*lst;
	static t_list	*start;

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
