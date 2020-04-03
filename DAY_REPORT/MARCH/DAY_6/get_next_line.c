#include "libft.h"

static int  ft_count(int fd, char **line)
{
    int     i;
    int     j;
    char    c;

    i = 0;
    while (line[i])
        i++;
    j = 0;
    while (j < i - 1)
    {
        read(fd, &c, 1);
        if (c == '\n')
            j++;
    }
    j = 0;
    while (read(fd, &c, 1) != '\n')
        j++;
    return (j);
}

int     get_next_line(int fd, char **line)
{
    int     i;
    int     j;
    int     count;
    char    *str;
    
    if (fd == NULL)
        return (-1);
    count = ft_count(fd, line);
    str = (char *)malloc(sizeof(char) * (count + 1));
    if (str == NULL)
        return (0);
    
}