#include "push_swap.h"

int		sort_a_else(t_stack** a, t_stack** b, int* pre, int num)
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
			if (check_a(*a, size(a)) && (*a)->content >= p2 && size(a) == s)
				break ;
			check_command(a, b, pre, RA);
			//stack_print(*a);
			//stack_print(*b);
		}
		else
		{
			//printf("a = %d, p1 = %d\n", (*a)->content, p1);
			check_command(a, b, pre, PB);
			//stack_print(*a);
			//stack_print(*b);
			if ((*b)->content > p1)
			{
				check_command(a, b, pre, RB);
				r_cnt++;
				//stack_print(*a);
				//stack_print(*b);
			}
			cnt++;
		}
	}
	sort_b(a, b, pre, cnt - r_cnt);
	for (s = 0; s < num - cnt && s < r_cnt; s++)
		check_command(a, b, pre, RRR);
	if (size(a) != num - cnt)
	{
		for (int i = s; i < num - cnt; i++)
			check_command(a, b, pre, RRA);
	}
	//stack_print(*a);
	//stack_print(*b);
	if (size(b) != r_cnt)
	{
		for (int i = s; i < r_cnt; i++)
			check_command(a, b, pre, RRB);
	//	stack_print(*a);
	//	stack_print(*b);
	}
	sort_a(a, b, pre, num - cnt);
	//stack_print(*a);
	//stack_print(*b);
	sort_b(a, b, pre, r_cnt);
	//stack_print(*a);
	//stack_print(*b);
	return (cnt);
}

int		sort_b_else(t_stack** a, t_stack** b, int* pre, int num)
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
			if (check_b(*b, size(b)) && (*b)->content < p1 && size(b) == s)
				break ;
		 	 check_command(a, b, pre, RB);
		
		//	stack_print(*a);
		//	stack_print(*b);
		}
		else
		{
			//stack_print(*a);
			//stack_print(*b);
			check_command(a, b, pre, PA);
			if ((*a)->content < p2)
			{
				check_command(a, b, pre, RA);
				//stack_print(*a);
				//stack_print(*b);
				r_cnt++;
			}
			cnt++;
		}
	}
	sort_a(a, b, pre, cnt - r_cnt);
	s = 0;
	for (s = 0; s < num - cnt && s < r_cnt; s++)
		check_command(a, b, pre, RRR);
	//	stack_print(*b);
	if (size(b) != num - cnt)
	{
		for (int i = s; i < num - cnt; i++)
			check_command(a, b, pre, RRB);
	}
	//	stack_print(*b);
	if (size(a) != r_cnt)
	{
		for (int i = s; i < r_cnt; i++)
			check_command(a, b, pre, RRA);
	}
	//stack_print(*a);
	//stack_print(*b);
	sort_b(a, b, pre, num - cnt);
	//stack_print(*a);
	//stack_print(*b);
	sort_a(a, b, pre, r_cnt);
	//stack_print(*a);
	//stack_print(*b);
	return (cnt);
}

void	sort_a(t_stack** a, t_stack** b, int* pre, int num)
{
	int			cnt;

	//ft_putstr_fd("sort_a = ", 1);
	//ft_putnbr_fd(num, 1);
	//ft_putstr_fd("\n", 1);
	if (num < 2)
		return ;
	else if (check_a(*a, num))
		return ;
	else if (num == 2){
		if ((*a)->next->content < (*a)->content)
			check_command(a, b, pre, SA);
		return ;
	}
	else if (num == 3)
		return (sort_a_three(a, b, pre));
	else
		cnt = sort_a_else(a, b, pre, num);
	//printf("cnt = %d\n", cnt);
	for (int i = 0; i < cnt; i++)
		check_command(a, b, pre, PA);
	//stack_print(*a);
	//stack_print(*b);
}

void	sort_b(t_stack** a, t_stack** b, int* pre, int num)
{
	int			cnt;

	//ft_putstr_fd("sort_b = ", 1);
	//ft_putnbr_fd(num, 1);
	//ft_putstr_fd("\n", 1);
	if (num < 2)
		return ;
	else if (check_b(*b, num))
		return ;
	else if (num == 2)
	{
	//	ft_putstr_fd("num is 2\n", 1);
		if ((*b)->next->content > (*b)->content)
			check_command(a, b, pre, SB);
		return ;
	}
	else if (num == 3)
		return (sort_b_three(a, b, pre));
	else
		cnt = sort_b_else(a, b, pre, num);
	//printf("cnt = %d\n", cnt);
	for (int i = 0; i < cnt; i++)
		check_command(a, b, pre, PB);
	//stack_print(*a);
	//stack_print(*b);
}

int			main(int argc, char* argv[])
{
	int			i;
	int			j;
	int			pre[2];
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
	pre[0] = 0;
	pre[1] = 0;
	sort_a(&a, &b, pre, size(&a));
	//if (pre[0] > 0 || pre[1] > 0)
	while (pre[0] && pre[1] > 0)
	{
		print_command(pre[0]);
		pre[1] -= 1;
	}
	//stack_print(a);
	//stack_print(b);
	clear(&a);
	clear(&b);
	return 0;
}
