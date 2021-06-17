#include "checker.h"

void		stack_print(t_stack*	head){
	t_stack*	tmp;

	if (head == NULL)
		return ;
	tmp = head;
	printf("%d, ", tmp->content);
	tmp = tmp->next;
	while (tmp != head){
		printf("%d, ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

int		check(t_stack* head, int *arr, int num){
	t_stack*	tmp;
	int			i;

	//printf("num = %d\n", num);
	stack_print(head);
	for (int j = 0; j < num; j++)
		printf("%d, ", arr[j]);
	printf("\n");
	i = 0;
	tmp = head;
	while (tmp != head->prev && i < num){
		if (tmp->content != arr[i])
			return 0;
		tmp = tmp->next;
		i++;
	}
	return 1;
}

char*		is_command(t_stack** a, t_stack** b, char* str){
	if (!(ft_strncmp("sa", str, 3)))
		swap(a);
	else if (!(ft_strncmp("sb", str, 3)))
		swap(b);
	else if (!(ft_strncmp("ss", str, 3))){
		swap(a);
		swap(b);
	}
	else if (!(ft_strncmp("pa", str, 3))){
		push(a, top(b));
		pop(b);
	}
	else if (!(ft_strncmp("pb", str, 3))){
		push(b, top(a));
		pop(a);
	}
	else if (!(ft_strncmp("ra", str, 3)))
		rotate(a);
	else if (!(ft_strncmp("rb", str, 3)))
		rotate(b);
	else if (!(ft_strncmp("rr", str, 3))){
		rotate(a);
		rotate(b);
	}
	else if (!(ft_strncmp("rra", str, 3)))
		reverse_rotate(a);
	else if (!(ft_strncmp("rrb", str, 3)))
		reverse_rotate(b);
	else if (!(ft_strncmp("rrr", str, 3))){
		reverse_rotate(a);
		reverse_rotate(b);
	}
	return str;
}

void	sort_arr(int *arr, int start, int end)
{
	int		i;
	int		j;
	int		pivot;

	if (end - start < 1)
		return ;
	pivot = end;
	i = start;
	while (i < pivot)
	{
		if (arr[i] > arr[pivot])
		{
			j = arr[pivot - 1];
			arr[pivot - 1] = arr[pivot];
			if (i != pivot - 1){
				arr[pivot] = arr[i];
				arr[i] = j;
			}
			else
				arr[pivot] = j;
			pivot--;
		}
		else
			i++;
	}
	sort_arr(arr, 0, pivot - 1);
	sort_arr(arr, pivot + 1, end);
}

int*			sort(t_stack* head, int num){
	int			i;
	int			*arr;
	t_stack*	tmp;

	if (!(arr = (int *)malloc(sizeof(int) * (num + 1))))
		return 0;
	i = 0;
	tmp = head;
	while (i < num)
	{
		arr[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	arr[i] = 0;
	//for (int j = 0; j < num; j++)
	//	printf("%d, ", arr[j]);
	//printf("\n");
	sort_arr(arr, 0, num - 1);
	return (arr);
}

int			main(int argc, char* argv[])
{
	int			i;
	int			j;
	int			s;
	int			*arr;
	t_stack*	a = 0;
	t_stack*	b = 0;
	char		**c;
	char		*cmd;

	if (argc < 2){
		printf("Input Error\n");
		return -1;
	}
	if (!(cmd = (char*)malloc(sizeof(char) * 4)))
		return 0;
	for (i = 1; i < argc; i++){
		c = ft_split(argv[i], ' ');
		j = 0;
		while (c[j]){
			push_back(&a, ft_atoi(c[j]));
			j++;
		}
		j = 0;
		while (c[j++])
			free(c[j]);
		free(c);
	}
	s = size(&a);
	stack_print(a);
	arr = sort(a, s);
	while (get_next_line(0, &cmd))
	{
		is_command(&a, &b, cmd);
		//stack_print(a);
		//stack_print(b);
		free(cmd);
	}
	if ((check(a, arr, s)))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear(&a);
	clear(&b);
	free(arr);
	//free(cmd);
	return 0;
}
