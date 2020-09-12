#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct		s_list
{
	void			*data;
	struct	s_list	*next;
}					t_list;

int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(const char *s);
ssize_t				ft_read(int fd, void *buf, size_t count);
ssize_t				ft_write(int fd, const void *buf, size_t nbyte);

int					ft_list_size(t_list *begin_list);
int					ft_atoi_base(const char *str, const char *base);
void				ft_list_sort(t_list **begin_list, int (*cmp)());
void				ft_list_push_front(t_list **begin_list, void *data);
void				ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

void				printf_list(t_list *list)
{
	while (list)
	{
		printf("data = %s, list = %p, next = %p\n", list->data, list, list->next);
		list = list->next;
	}
}

void				ft_lstclear(t_list **list)
{
	t_list			*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

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
	t_list	*list;
	
	i = -1;
	while (++i < 20)
		buf[i] = 0;
	
	printf("-------------------------------- FT_ATOI_BASE -----------------------------------------\n\n");
	printf("BASE = \'0123456789\', \'42\'			: ft_atoi_base = %d\n", ft_atoi_base("42", "0123456789"));
	printf("BASE = \'0123456789\', \'0\'			: ft_atoi_base = %d\n", ft_atoi_base("0", "0123456789"));
	printf("BASE = \'0123456789\', \'123123123\'		: ft_atoi_base = %d\n", ft_atoi_base("123123123", "0123456789"));
	printf("BASE = \'0123456789\', \'-0\'			: ft_atoi_base = %d\n", ft_atoi_base("-0", "0123456789"));
	printf("BASE = \'0123456789\', \'-1\'			: ft_atoi_base = %d\n", ft_atoi_base("-1", "0123456789"));
	printf("BASE = \'0123456789\', \'  -+-42\'			: ft_atoi_base = %d\n", ft_atoi_base("  -+-42", "0123456789"));
	printf("BASE = \'0123456789\', \'  -+- -42\'		: ft_atoi_base = %d\n", ft_atoi_base("  -+- -42", "0123456789"));
	printf("BASE = \'0123456789\', \'2147483647\'		: ft_atoi_base = %d\n", ft_atoi_base("2147483647", "0123456789"));
	printf("BASE = \'0123456789\', \'-2147483648\'		: ft_atoi_base = %d\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("BASE = \'0123456789\', \'2147483648\'		: ft_atoi_base = %d\n", ft_atoi_base("2147483648", "0123456789"));
	printf("BASE = \'0123456789\', \'-2147483649\'		: ft_atoi_base = %d\n", ft_atoi_base("-2147483649", "0123456789"));
	printf("BASE = \'0123456789abcdef\', \'a\'			: ft_atoi_base = %d\n", ft_atoi_base("a", "0123456789abcdef"));
	printf("BASE = \'0123456789abcdef\', \'abc\'		: ft_atoi_base = %d\n", ft_atoi_base("abc", "0123456789abcdef"));
	printf("BASE = \'0123456789abcdef\', \'   +-+-12a\'		: ft_atoi_base = %d\n", ft_atoi_base("   +-+-12a", "0123456789abcdef"));
	printf("BASE = \'0123456789abcdef\', \'---ab\'		: ft_atoi_base = %d\n", ft_atoi_base("---ab", "0123456789abcdef"));
	printf("BASE = \'poney\', \'poney\'				: ft_atoi_base = %d\n", ft_atoi_base("poney", "poney"));
	printf("BASE = \'damage\', \'age\'				: ft_atoi_base = %d\n", ft_atoi_base("age", "damage"));
	printf("BASE = \'domage\', \'age\'				: ft_atoi_base = %d\n", ft_atoi_base("age", "domage"));
	printf("BASE = \'do mage\', \'age\'				: ft_atoi_base = %d\n", ft_atoi_base("age", "do mage"));
	printf("BASE = \'0123456789\', \'42age\'			: ft_atoi_base = %d\n", ft_atoi_base("42age", "0123456789"));
	printf("BASE = \'0123456789\', \'-42age\'			: ft_atoi_base = %d\n", ft_atoi_base("-42age", "0123456789"));
	

	printf("-------------------------------- FT_LIST_PUSH_FRONT ------------------------------\n\n");

	list = NULL;
	printf("Before:\n\n");
	printf_list(list);
	printf("first:\n");
	ft_list_push_front(&list, strdup("first"));
	printf_list(list);
	printf("\nsecond:\n");
	ft_list_push_front(&list, strdup("second"));
	printf_list(list);
	printf("\nthird:\n");
	ft_list_push_front(&list, strdup("third"));
	printf_list(list);
	printf("\nforth:\n");
	ft_list_push_front(&list, strdup("forth"));
	printf_list(list);

	printf("-------------------------------- FT_LIST_SIZE ------------------------------------\n\n");
	
	printf("list_size = %d\n", ft_list_size(list));
	printf("print_start__\n");
	printf_list(list);
	printf("print_end__\n\n");
	ft_lstclear(&list);
	printf("list_size = %d\n", ft_list_size(list));
	printf("print_start__\n");
	printf_list(list);
	printf("print_end__\n\n");
	
	printf("-------------------------------- FT_LIST_SORT ------------------------------------\n\n");
	
	ft_list_push_front(&list, NULL);
	ft_list_push_front(&list, strdup("apple"));
	ft_list_push_front(&list, strdup(""));
	ft_list_push_front(&list, strdup("banana"));
	ft_list_push_front(&list, strdup("ears"));
	ft_list_push_front(&list, strdup("foot"));
	ft_list_push_front(&list, strdup("hippo"));
	ft_list_push_front(&list, NULL);
	ft_list_push_front(&list, strdup("candy"));
	ft_list_push_front(&list, NULL);

	printf("Before:\n");
	printf_list(list);
	printf("\nAfter:\n");
	//ft_list_sort(&list, &strcmp);
	printf_list(list);

	printf("-------------------------------- FT_LIST_REMOVE_IF -------------------------------\n\n");
	
	printf("Before:\n");
	printf_list(list);
	
	printf("\nlist->data = \'%s\'\n", "ears");
	ft_list_remove_if(&list, "ears", &strcmp, &free);
	printf_list(list);
	printf("\nlist->data = \'%s\'\n", NULL);
	ft_list_remove_if(&list, NULL, &strcmp, &free);
	printf_list(list);
	printf("\nlist->data = \'%s\'\n", "");
	ft_list_remove_if(&list, "", &strcmp, &free);
	printf_list(list);
	printf("\nlist->data = \'%s\'\n", "hippo");
	ft_list_remove_if(&list, "hippo", &strcmp, &free);
	printf_list(list);
	printf("\nlist->data = \'%s\'\n", "apple");
	ft_list_remove_if(&list, "apple", &strcmp, &free);
	printf_list(list);

	ft_lstclear(&list);
	return (0);
}
