#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int     get_next_line(int fd, char **line)
{
    int             i;
    int             j;
    int             re;
    int             count;
    static char     *buf;
    
    count = 0;
    while (line[count])
        count++;
    i = 0;
    re = 0;
    printf("start!\n");
    while((re = read(fd, buf, BUFSIZ)))
    {
        while (*(buf + i) != '\n')
            i++;
        if (*(buf + i) = '\n')
            break   ;
    }
    if (re == -1)
        return (-1);
    printf("i = %d\n", i);
    line[count] = (char *)malloc(sizeof(char) * (i + 1));
    if (line[count] = NULL)
        return (-1);
    j = -1;
    while (++j < i)
        line[count][j] = buf[j];
    line[count][j] = 0;
    return (re);
}

int     main(){
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
        if (buf_str[i] == '\n'){
        line[k] = (char *)malloc(sizeof(char) * (i + 1));
        if (line[k] == NULL)
            return (0);
        for (int j = 0; j < i; j++)
        line[k][j] = buf_str[j];
        line[k][j] = 0;
        k++;
        break ;
        }
    i++;
    }
    while (get_next_line(fd, line))
    k = 0;
    while (line[k]){
        printf("k = %d, !%s!\n", k, line[k]);
        k++;
    }
    close(fd);
    free(line);
    return (0);
}