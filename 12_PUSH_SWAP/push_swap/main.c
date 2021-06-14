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

void		is_command(t_stack** a, t_stack** b, int cmd){
	if (cmd == SA)
		swap(a);
	else if (cmd == SB)
		swap(b);
	else if (cmd == SS)
	{
		swap(a);
		swap(b);
	}
	else if (cmd == PA)
	{
		push(a, top(b));
		pop(b);
	}
	else if (cmd == PB)
	{
		push(b, top(a));
		pop(a);
	}
	else if (cmd == RA)
		rotate(a);
	else if (cmd == RB)
		rotate(b);
	else if (cmd == RR)
	{
		rotate(a);
		rotate(b);
	}
	else if (cmd == RRA)
		reverse_rotate(a);
	else if (cmd == RRB)
		reverse_rotate(b);
	else if (cmd == RRR)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
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

void		find_pivot(t_stack* head, int num, int *p1, int *p2){
	int			i;
	int			*arr;
	t_stack*	tmp;

	if (!(arr = (int *)malloc(sizeof(int) * (num + 1))))
		return ;
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
	*p1 = arr[num / 3];
	*p2 = arr[num / 3 * 2];
	if (num / 3 == 0)
	{
		*p1 -= 1;
		*p2 -= 1;
	}
	free(arr);
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

int		sort_a_else(t_stack** a, t_stack** b, int num)
{
	int			p1;
	int			p2;
	int			cnt;
	int			r_cnt;
	int			s;

	cnt = 0;
	r_cnt = 0;
	s = size(a);
	find_pivot(*a, num, &p1, &p2);
	//printf("p1 = %d, p2 = %d\n", p1, p2);
	for (int i = 0; i < num; i++)
	{
		if ((*a)->content >= p2)
		{
			if ((*a)->next->content >= p2
					&& (*a)->content > (*a)->next->content
					&& i != num - 1)
				printf("%s\n", is_command(a, b, "sa"));
			printf("%s\n", is_command(a, b, "ra"));
			//stack_print(*a);
			//stack_print(*b);
		}
		else
		{
			if ((*a)->next->content < p2
					&& (*a)->content > (*a)->next->content
					&& i != num - 1)
				printf("%s\n", is_command(a, b, "sa"));
			//if (cnt == 0 && check_a(*a, num))
			//	break ;
			printf("%s\n", is_command(a, b, "pb"));
			//stack_print(*a);
			//stack_print(*b);
			if ((*b)->content > p1)
			{
				printf("%s\n", is_command(a, b, "rb"));
				r_cnt++;
			//	stack_print(*a);
			//	stack_print(*b);
			}
			cnt++;
		}
	}
	sort_b(a, b, cnt - r_cnt);
	for (s = 0; s < num - cnt && s < r_cnt; s++)
		printf("%s\n", is_command(a, b, "rrr"));
	for (int i = s; i < num - cnt; i++)
		printf("%s\n", is_command(a, b, "rra"));
	//stack_print(*a);
	//stack_print(*b);
	for (int i = s; i < r_cnt; i++)
		printf("%s\n", is_command(a, b, "rrb"));
	//stack_print(*a);
	//stack_print(*b);
	sort_a(a, b, num - cnt);
	sort_b(a, b, r_cnt);
	return (cnt);
}

int		sort_b_else(t_stack** a, t_stack** b, int num)
{
	int			p1;
	int			p2;
	int			cnt;
	int			r_cnt;
	int			s;

	cnt = 0;
	r_cnt = 0;
	s = size(b);
	find_pivot(*b, num, &p1, &p2);
	//printf("p1 = %d, p2 = %d\n", p1, p2);
	for (int i = 0; i < num; i++)
	{
		if ((*b)->content < p1)
		{
			if ((*b)->next->content < p1
					&& (*b)->content < (*b)->next->content
					&& i != num - 1)
				printf("%s\n", is_command(a, b, "sb"));
			printf("%s\n", is_command(a, b, "rb"));
			//stack_print(*a);
			//stack_print(*b);
		}
		else
		{
			if ((*b)->next->content >= p1
					&& (*b)->content < (*b)->next->content
					&& i != num - 1)
				printf("%s\n", is_command(a, b, "sb"));
			//stack_print(*a);
			//stack_print(*b);
			//if (cnt == 0 && check_b(*b, num))
			//	break ;
			printf("%s\n", is_command(a, b, "pa"));
			if ((*a)->content < p2)
			{
				printf("%s\n", is_command(a, b, "ra"));
			//	stack_print(*a);
			//	stack_print(*b);
				r_cnt++;
			}
			cnt++;
		}
	}
	sort_a(a, b, cnt - r_cnt);
	for (s = 0; s < num - cnt && s < r_cnt; s++)
		printf("%s\n", is_command(a, b, "rrr"));
//	stack_print(*b);
	for (int i = s; i < num - cnt; i++)
		printf("%s\n", is_command(a, b, "rrb"));
//	stack_print(*b);
	for (int i = s; i < r_cnt; i++)
		printf("%s\n", is_command(a, b, "rra"));
//	stack_print(*b);
	sort_b(a, b, num - cnt);
	sort_a(a, b, r_cnt);
	return (cnt);
}

void	sort_a(t_stack** a, t_stack** b, int num)
{
	int			cnt;

//	printf("sort_a = %d\n", num);
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
	for (int i = 0; i < cnt; i++)
		printf("%s\n", is_command(a, b, "pa"));
	//stack_print(*a);
	//stack_print(*b);
}

void	sort_b(t_stack** a, t_stack** b, int num)
{
	int			cnt;

	//printf("sort_b = %d\n", num);
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
	for (int i = 0; i < cnt; i++)
		printf("%s\n", is_command(a, b, "pb"));
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
