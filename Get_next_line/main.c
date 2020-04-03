#include "get_next_line.h"

int main() 
{
	char    c;
	char    *line;
    int     i; 
    int     fd = open("test.txt", O_RDWR);
  
	if (fd == -1)
	  return (-1);

    BUFFER_SIZE = 100;
/*
    for (int j = 0; j < 7; j++)
    {
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