#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

void    ft_lstclear(t_list **lst)
{
    t_list  *L;
    t_list  *front;

    L = *lst;
    while (L->next)
    {
        front = L;
        L = L->next;
        free(front);
    }
    free(L);
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

int     ft_check(char *str, int re)
{
    int   i;

    i = 0;
    while (i < re)
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    if (i == re)
        return (0);
    else
        return (i);
}

void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
    unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		if (*((char *)src + i) == c)
        {
            *((char *)src + i) = c;
            *((char *)src + i + 1) = 0;
			return ((char *)dest + i + 2);
        }
        i++;
	}
	return (0);
}

int     get_next_line(int fd, char **line)
{
    int     i;
    int     j;
    int     re;
    t_list  n;
    t_list  **lst;
    static t_list  *start;

    n.content = (char *)malloc(sizeof(char) * (BUFSIZ + 1));
    if (n.content == NULL)
        return (-1);
    lst = &start;
    ft_lstadd_back(&start, ft_lstnew());
    i = ft_check((*lst)->content, re);
    printf("!i! = %d\n", i);
    while ((re = read(fd, n.content, BUFSIZ)) != -1)
    {
        printf("re = %d\n", re);
        if (re == -1)
            return (-1);
        else if (re == 0)
            return (0);
        ft_lstadd_back(&start, ft_lstnew());
        while ((*lst)->next)
            *lst = (*lst)->next;
        ft_memccpy((*lst)->content, n.content, -1, BUFSIZ);
        printf("lst = %s\n", (*lst)->content);
        if ((i += ft_check((*lst)->content, re)))
            break;
    }
    printf("i = %d\n", i);
    j = 0;
    while (line[j])
        j++;
    line[j] = (char *)malloc(sizeof(char) * (i + 1));
    if (line[j] == NULL)
        return (-1);
    while (1)
    {
        if (i > BUFSIZ)
        {
            lst = &start;
            start = start->next;
            free(*lst);
            i -= BUFSIZ;
            ft_memccpy(line[j], start->content, '\n', BUFSIZ);
        }
        else
        {
            ft_memccpy(line[j], start->content, '\n', i);
            break;
        }
    }
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
    printf("line[0] = %s\n", line[0]);
    get_next_line(fd, line);
    get_next_line(fd, line);
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