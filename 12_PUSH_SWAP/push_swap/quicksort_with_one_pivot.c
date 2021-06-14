#include "push_swap.h"

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

int		check_a(t_stack* head, int num){
	t_stack*	tmp;
	int			i;

	i = 0;
	tmp = head->next;
	while (tmp != head && i < num){
		if (tmp->content < tmp->prev->content)
			return 0;
		tmp = tmp->next;
		i++;
	}
	return 1;
}

int		check_b(t_stack* head, int num){
	t_stack*	tmp;
	int			i;

	i = 0;
	tmp = head->next;
	while (tmp != head && i < num){
		if (tmp->content > tmp->prev->content)
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

	//printf("sort_arr = %d, %d\n", start, end);
	if (end - start < 1)
		return ;
	pivot = end;
	i = start;
	//printf("p = %d\n", pivot);
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

int		find_pivot(t_stack* head, int num){
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
	sort_arr(arr, 0, num - 1);
	if (num / 2)
		i = arr[num / 2];
	else
		i = arr[num / 2 - 1];
	free(arr);
	return (i);
}

void	sort_a_three(t_stack **a, t_stack **b)
{
	if ((*a)->content > (*a)->next->content)
		printf("%s\n", is_command(a, b, "sa"));
	printf("%s\n", is_command(a, b, "ra"));
	if ((*a)->content > (*a)->next->content)
		printf("%s\n", is_command(a, b, "sa"));
	printf("%s\n", is_command(a, b, "rra"));
	if ((*a)->content > (*a)->next->content)
		printf("%s\n", is_command(a, b, "sa"));
}

void	sort_b_three(t_stack **a, t_stack **b)
{
	if ((*b)->content < (*b)->next->content)
		printf("%s\n", is_command(a, b, "sb"));
	printf("%s\n", is_command(a, b, "rb"));
	if ((*b)->content < (*b)->next->content)
		printf("%s\n", is_command(a, b, "sb"));
	printf("%s\n", is_command(a, b, "rrb"));
	if ((*b)->content < (*b)->next->content)
		printf("%s\n", is_command(a, b, "sb"));
}

int		sort_b_else(t_stack** a, t_stack** b, int num)
{
	int			cnt;
	int			pivot;
	int			s;
	
	cnt = 0;
	s = size(b);
	pivot = find_pivot(*b, num);
	//printf("pivot = %d\n", pivot);
	for (int i = 0; i < num; i++)
	{
		if ((*b)->content >= pivot)
		{
			if ((*b)->next->content >= pivot
					&& (*b)->content < (*b)->next->content
					&& i != num - 1)
			{
				printf("%s\n", is_command(a, b, "sb"));
				//stack_print(*b);
			}
			printf("%s\n", is_command(a, b, "pa"));
			//stack_print(*b);
			cnt++;
		}
		else {
			if ((*b)->next->content < pivot
					&& (*b)->content < (*b)->next->content
					&& i != num - 1)
			{
				printf("%s\n", is_command(a, b, "sb"));
			//	stack_print(*b);
			}
			if (check_b(*b, size(b)) && cnt == 0)
				break ;
			printf("%s\n", is_command(a, b, "rb"));
			//stack_print(*b);
		}
	}
	if (s > num)
	{
		for (int i = 0; i < num - cnt; i++)
			printf("%s\n", is_command(a, b, "rrb"));
	}
	//stack_print(*b);
	return (cnt);
}

void	sort_b(t_stack** a, t_stack** b, int num)
{
	int		cnt;

	//printf("sort_b, %d\n", num);
	if (num < 2)
		return ;
	else if (check_b(*b, num))
		return ;
	else if (num == 2){
		if ((*b)->next->content > (*b)->content)
			printf("%s\n", is_command(a, b, "sb"));
		return ;
	}
	else if (num == 3)
		return (sort_b_three(a, b));
	else
		cnt = sort_b_else(a, b, num);
	sort_a(a, b, cnt);
	sort_b(a, b, num - cnt);
	for (int i = 0; i < cnt; i++)
		printf("%s\n", is_command(a, b, "pb"));
}

int		sort_a_else(t_stack** a, t_stack** b, int num)
{
	int			pivot;
	int			cnt;
	int			s;

	cnt = 0;
	s = size(a);
	pivot = find_pivot(*a, num);
	//printf("pivot = %d, num = %d\n", pivot, num);
	for (int i = 0; i < num; i++)
	{
		if ((*a)->content >= pivot)
		{
			if ((*a)->next->content >= pivot
					&& (*a)->content > (*a)->next->content
					&& i != num - 1)
			{
				printf("%s\n", is_command(a, b, "sa"));
				//stack_print(*a);
			}
			if (check_a(*a, size(a)) && cnt == 0)
				break ;
			printf("%s\n", is_command(a, b, "ra"));
			//stack_print(*a);
		}
		else
		{
			if ((*a)->next->content < pivot
					&& (*a)->content > (*a)->next->content
					&& i != num - 1)
			{
				printf("%s\n", is_command(a, b, "sa"));
				//stack_print(*a);
			}
			printf("%s\n", is_command(a, b, "pb"));
			//stack_print(*a);
			cnt++;
		}
	}
	if (s > num)
	{
		for (int i = 0; i < num - cnt; i++)
			printf("%s\n", is_command(a, b, "rra"));
	}
	//stack_print(*a);
	return (cnt);
}

void	sort_a(t_stack** a, t_stack** b, int num)
{
	int			cnt;

	//printf("quicksort, %d\n", num);
	if (num < 2)
		return ;
	else if (check_a(*a, num))
		return ;
	else if (num == 2){
		if ((*a)->next->content < (*a)->content)
			printf("%s\n", is_command(a, b, "sa"));
		return ;
	}
	else if (num == 3)
		return (sort_a_three(a, b));
	else
		cnt = sort_a_else(a, b, num);
	sort_b(a, b, cnt);
	sort_a(a, b, num - cnt);
	for (int i = 0; i < cnt; i++)
		printf("%s\n", is_command(a, b, "pa"));
	//stack_print(*a);
	//stack_print(*b);
}

int			main(int argc, char* argv[])
{
	int			i;
	int			j;
	t_stack*	a = 0;
	t_stack*	b = 0;
	char		**c;

	if (argc < 2){
		printf("Input Error\n");
		return -1;
	}
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
	//stack_print(a);
	sort_a(&a, &b, size(&a));
	clear(&a);
	clear(&b);
	return 0;
}
