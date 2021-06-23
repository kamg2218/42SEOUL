#include "push_swap.h"
/*
int				sort_a_else(t_stack **a, t_stack **b, int *pre, int num)
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
	for (int i = 0; i < num; i++)
	{
		if ((*a)->content >= p2)
		{
			check_command(a, b, pre, RA);
		}
		else
		{
			check_command(a, b, pre, PB);
			if ((*b)->content > p1)
			{
				check_command(a, b, pre, RB);
				r_cnt++;
			}
			cnt++;
		}
	}
	sort_b(a, b, pre, cnt - r_cnt);
	s = 0;
	if (size(a) != num - cnt && size(b) != r_cnt)
	{
		for (s = 0; s < num - cnt && s < r_cnt; s++)
			check_command(a, b, pre, RRR);
	}
	if (size(a) != num - cnt)
	{
		for (int i = s; i < num - cnt; i++)
			check_command(a, b, pre, RRA);
	}
	if (size(b) != r_cnt)
	{
		for (int i = s; i < r_cnt; i++)
			check_command(a, b, pre, RRB);
	}
	sort_a(a, b, pre, num - cnt);
	sort_b(a, b, pre, r_cnt);
	return (cnt);
}

int				sort_b_else(t_stack **a, t_stack **b, int *pre, int num)
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
	for (int i = 0; i < num; i++)
	{
		if ((*b)->content < p1)
		{
		 	 check_command(a, b, pre, RB);
		}
		else
		{
			check_command(a, b, pre, PA);
			if ((*a)->content < p2)
			{
				check_command(a, b, pre, RA);
				r_cnt++;
			}
			cnt++;
		}
	}
	sort_a(a, b, pre, cnt - r_cnt);
	s = 0;
	if (size(b) != num - cnt && size(a) != r_cnt)
	{
		for (s = 0; s < num - cnt && s < r_cnt; s++)
			check_command(a, b, pre, RRR);
	}
	if (size(b) != num - cnt)
	{
		for (int i = s; i < num - cnt; i++)
			check_command(a, b, pre, RRB);
	}
	if (size(a) != r_cnt)
	{
		for (int i = s; i < r_cnt; i++)
			check_command(a, b, pre, RRA);
	}
	sort_b(a, b, pre, num - cnt);
	sort_a(a, b, pre, r_cnt);
	return (cnt);
}
*/
void			sort_a(t_param *param, int num)
{
	int			i;
	int			cnt;

	if (num < 2)
		return ;
	else if (check_a(param->a, num))
		return ;
	else if (num == 2){
		if ((param->a)->next->content < (param->a)->content)
			check_command(param, SA);
		return ;
	}
	else if (num == 3)
		return (sort_a_three(param));
	else
		cnt = sort_a_else(param, num);
	i = 0;
	while (i++ < cnt)
		check_command(param, PA);
}

void			sort_b(t_param *param, int num)
{
	int			i;
	int			cnt;

	if (num < 2)
		return ;
	else if (check_b(param->b, num))
		return ;
	else if (num == 2)
	{
		if ((param->b)->next->content > (param->b)->content)
			check_command(param, SB);
		return ;
	}
	else if (num == 3)
		return (sort_b_three(param));
	else
		cnt = sort_b_else(param, num);
	i = 0;
	while (i++ < cnt)
		check_command(param, PB);
}

int				main(int argc, char* argv[])
{
	t_param		param;

	param.a = pre_processing(argc, argv, &param.pre);
	if (param.a == NULL)
		return (-1);
	param.b = NULL;
	sort_a(&param, size(&param.a));
	while (param.pre[0] && param.pre[1] > 0)
	{
		print_command(param.pre[0]);
		param.pre[1] -= 1;
	}
	clear(&param.a);
	if (param.b)
		clear(&param.b);
	return 0;
}
