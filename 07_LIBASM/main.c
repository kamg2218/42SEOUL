#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
char		*ft_strcpy(char *dest, const char *src);
size_t		ft_strlen(const char *s);
ssize_t		ft_read(int fd, void *buf, size_t count);
ssize_t		ft_write(int fd, const void *buf, size_t nbyte);

int			numcmp(int n, int m)
{
	if (n == m)
		return (0);
	else
		return (1);
}

char	check(int num)
{
	if (num == 0)
		return ('V');
	else
		return ('X');
}

int			main(void)
{
	int		i;
	int		a;
	int		b;
	char	*s1;
	char	*s2;
	char	buf[20];
	
	i = -1;
	while (++i < 20)
		buf[i] = 0;
	printf("------------------------------------ STRLEN ---------------------------------------------\n\n");
	a = strlen("");
	b = ft_strlen("");
	printf("\"%s\"			: strlen = %d			ft_strlen = %d			%c\n", "", a, b, check(numcmp(a, b)));
	a = strlen("abcd");
	b = ft_strlen("abcd");
	printf("\"%s\"	 		: strlen = %d			ft_strlen = %d			%c\n", "abcd", a, b, check(numcmp(a, b)));
	a = strlen("abcdefgh");
	b = ft_strlen("abcdefgh");
	printf("\"%s\" 		: strlen = %d			ft_strlen = %d			%c\n", "abcdefgh", a, b, check(numcmp(a, b)));
	a = strlen("0123456789");
	b = ft_strlen("0123456789");
	printf("\"%s\" 		: strlen = %d			ft_strlen = %d			%c\n", "0123456789", a, b, check(numcmp(a, b)));
	a = strlen("42");
	b = ft_strlen("42");
	printf("\"%s\"			: strlen = %d			ft_strlen = %d			%c\n", "42", a, b, check(numcmp(a, b)));
	b = ft_strlen(NULL);
	printf("\"NULL\"			: strlen = ERROR		ft_strlen = %d			%c\n", b, check(numcmp(0, b)));
	
	printf("\n------------------------------------ STRCPY ---------------------------------------------\n\n");
	s2 = ft_strcpy(buf, NULL);
	printf("\"NULL\"			: strcpy = ERROR		ft_strcpy = \'%s\'\n", s2);
	s2 = ft_strcpy(NULL, "");
	printf("\"NULL\"			: strcpy = ERROR		ft_strcpy = \'%s\'\n", s2);
	s1 = strcpy(buf, "");
	s2 = ft_strcpy(buf, "");
	printf("\"%s\"			: strcpy = \'%s\'			ft_strcpy = \'%s\'			%c\n", "", s1, s2, check(strcmp(s1, s2)));
	s1 = strcpy(buf, "abcd");
	s2 = ft_strcpy(buf, "abcd");
	printf("\"%s\"			: strcpy = \'%s\'		ft_strcpy = \'%s\'		%c\n", "abcd", s1, s2, check(strcmp(s1, s2)));
	s1 = strcpy(buf, "hello world");
	s2 = ft_strcpy(buf, "hello world");
	printf("\"%s\"		: strcpy = \'%s\'	ft_strcpy = \'%s\'	%c\n", "hello world", s1, s2, check(strcmp(s1, s2)));
	s1 = strcpy(buf, "012345");
	s2 = ft_strcpy(buf, "012345");
	printf("\"%s\"		: strcpy = \'%s\'		ft_strcpy = \'%s\'		%c\n", "012345", s1, s2, check(strcmp(s1, s2)));
	
	printf("\n------------------------------------ STRCMP ---------------------------------------------\n\n");
	a = strcmp("013", "012345");
	b = ft_strcmp("013", "012345");
	printf("\"%s\"	- \"%s\"	: strcmp = %d			ft_strcmp = %d			%c\n", "013", "012345", a, b, check(numcmp(a, b)));
	a = strcmp("002", "012345");
	b = ft_strcmp("002", "012345");
	printf("\"%s\"	- \"%s\"	: strcmp = %d			ft_strcmp = %d			%c\n", "002", "012345", a, b, check(numcmp(a, b)));
	a = strcmp("abcde", "ab");
	b = ft_strcmp("abcde", "ab");
	printf("\"%s\" - \"%s\"		: strcmp = %d			ft_strcmp = %d			%c\n", "abcde", "ab", a, b, check(numcmp(a, b)));
	a = strcmp("ab", "abcde");
	b = ft_strcmp("ab", "abcde");
	printf("\"%s\"    - \"%s\"	: strcmp = %d			ft_strcmp = %d			%c\n", "ab", "abcde", a, b, check(numcmp(a, b)));
	a = strcmp("abcde", "abcde");
	b = ft_strcmp("abcde", "abcde");
	printf("\"%s\" - \"%s\"	: strcmp = %d			ft_strcmp = %d			%c\n", "abcde", "abcde", a, b, check(numcmp(a, b)));
	b = ft_strcmp("toto", NULL);
	printf("\"%s\"  - \"NULL\"	: strcmp = ERROR		ft_strcmp = %d			%c\n", "toto", b, check(numcmp(1, b)));
	b = ft_strcmp(NULL, "toto");
	printf("\"NULL\"  - \"%s\"	: strcmp = ERROR		ft_strcmp = %d			%c\n", "toto", b, check(numcmp(-1, b)));
	b = ft_strcmp(NULL, NULL);
	printf("\"NULL\"  - \"NULL\"	: strcmp = ERROR		ft_strcmp = %d			%c\n", b, check(numcmp(0, b)));
	b = ft_strcmp(NULL, "");
	printf("\"NULL\"  - \"%s\"		: strcmp = ERROR		ft_strcmp = %d			%c\n", "", b, check(numcmp(-1, b)));
	b = ft_strcmp("", NULL);
	printf("\"%s\"      - \"NULL\"	: strcmp = ERROR		ft_strcmp = %d			%c\n", "", b, check(numcmp(1, b)));

	printf("\n------------------------------------ WRITE ----------------------------------------------\n\n");
	write(1, "fd = 1, \"", 9);
	write(1, "abcde", 5);
	write(1, "\", nbyte = 3	: write = \'", 24);
	a = write(1, "abcde", 3);
	write(1, "\'		ft_write = \'", 15);
	b = ft_write(1, "abcde", 3);
	write(1, "\'		", 3);
	buf[0] = check(numcmp(a, b));
	write(1, &buf[0], 1);
	write(1, "\n", 1);
	
	write(1, "fd = 1, \"", 9);
	write(1, "abcde", 5);
	write(1, "\", nbyte = 6	: write = \'", 24);
	a = write(1, "abcde", 6);
	write(1, "\'	ft_write = \'", 14);
	b = ft_write(1, "abcde", 6);
	write(1, "\'			", 3);
	buf[0] = check(numcmp(a, b));
	write(1, &buf[0], 1);
	write(1, "\n", 1);
	
	write(1, "fd = 1, \"", 9);
	write(1, "abcde", 5);
	write(1, "\", nbyte = 1	: write = \'", 24);
	a = write(1, "abcde", 1);
	write(1, "\'		ft_write = \'", 15);
	b = ft_write(1, "abcde", 1);
	write(1, "\'			", 4);
	buf[0] = check(numcmp(a, b));
	write(1, &buf[0], 1);
	write(1, "\n", 1);

	write(1, "fd = 1, \"", 9);
	write(1, "abcde", 5);
	write(1, "\", nbyte = 0	: write = \'", 24);
	a = write(1, "abcde", 0);
	write(1, "\'		ft_write = \'", 15);
	b = ft_write(1, "abcde", 0);
	write(1, "\'			", 4);
	buf[0] = check(numcmp(a, b));
	write(1, &buf[0], 1);
	write(1, "\n", 1);
	
	printf("\n------------------------------------ READ -----------------------------------------------\n\n");
	
	i = -1;
	while (++i < 20)
		buf[i] = 0;
	a = ft_read(0, buf, 0);
	printf("count = 0, \'%s\'		%c\n", buf, check(numcmp(strlen(buf), 0)));
	a = ft_read(0, buf, 1);
	printf("count = 1, \'%s\'		%c\n", buf, check(numcmp(strlen(buf), 1)));
	a = ft_read(0, buf, 2);
	printf("count = 2, \'%s\'		%c\n", buf, check(numcmp(strlen(buf), 2)));
	a = ft_read(0, buf, 5);
	printf("count = 5, \'%s\'		%c\n", buf, check(numcmp(strlen(buf), 5)));
	a = ft_read(0, buf, 10);
	printf("count = 10, \'%s\'	%c\n", buf, check(numcmp(strlen(buf), 10)));
	getchar();
	
	printf("\n------------------------------------ STRDUP ---------------------------------------------\n\n");
	
	i = -1;
	while (++i < 20)
		buf[i] = 0;
	
	s1 = strdup("");
	s2 = ft_strdup("");
	printf("\"%s\"			: strdup = \'%s\'			ft_strdup = \'%s\'			%c\n", "", s1, s2, check(strcmp(s1, s2)));
	s1 = strdup("hello");
	s2 = ft_strdup("hello");
	printf("\"%s\"			: strdup = \'%s\'		ft_strdup = \'%s\'		%c\n", "hello", s1, s2, check(strcmp(s1, s2)));
	s1 = strdup("long long ago");
	s2 = ft_strdup("long long ago");
	printf("\"%s\"		: strdup = \'%s\'	ft_strdup = \'%s\'	%c\n", "long long ago", s1, s2, check(strcmp(s1, s2)));
	s1 = strdup("a b c d e f ");
	s2 = ft_strdup("a b c d e f ");
	printf("\"%s\"		: strdup = \'%s\'	ft_strdup = \'%s\'	%c\n", "a b c d e f ", s1, s2, check(strcmp(s1, s2)));
	s2 = ft_strdup(NULL);
	printf("\"NULL\"			: strdup = ERROR		ft_strdup = \'%s\'		%c\n", s2, check(ft_strcmp(NULL, s2)));

	printf("\n-------------------------------------- END ------------------------------------------------\n\n");

	return (0);
}
