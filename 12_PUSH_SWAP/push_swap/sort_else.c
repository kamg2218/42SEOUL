#include "push_swap.h"

int				arrange_a(t_param *param, int *p)
{
	if (param->a->content >= p[1])
		check_command(param, RA);
	else
	{
		check_command(param, PB);
		if (param->b->content > p[0])
		{
			check_command(param, RB);
			return (2);
		}
		return (1);
	}
	return (0);
}

int				arrange_b(t_param *param, int *p)
{
	if (param->b->content < p[0])
		check_command(param, RB);
	else
	{
		check_command(param, PA);
		if (param->a->content < p[1])
		{
			check_command(param, RA);
			return (2);
		}
		return (1);
	}
	return (0);
}

void			reverse_rotate_a(t_param *param, int cnt, int r_cnt)
{
	int			i;
	int			j;

	j = 0;
	if (size(&param->a) != cnt && size(&param->b) != r_cnt)
	{
		while (j < cnt && j++ < r_cnt)
			check_command(param, RRR);
	}
	if (size(&param->a) != cnt)
	{
		i = j;
		while (i++ < cnt)
			check_command(param, RRA);
	}
	if (size(&param->b) != r_cnt)
	{
		i = j;
		while (i++ < r_cnt)
			check_command(param, RRB);
	}
	sort_a(param, cnt);
	sort_b(param, r_cnt);
}

void			reverse_rotate_b(t_param *param, int cnt, int r_cnt)
{
	int			i;
	int			j;

	j = 0;
	if (size(&param->b) != cnt && size(&param->a) != r_cnt)
	{
		while (j < cnt && j++ < r_cnt)
			check_command(param, RRR);
	}
	if (size(&param->b) != cnt)
	{
		i = j;
		while (i++ < cnt)
			check_command(param, RRB);
	}
	if (size(&param->a) != r_cnt)
	{
		i = j;
		while (i++ < r_cnt)
			check_command(param, RRA);
	}
	sort_b(param, cnt);
	sort_a(param, r_cnt);
}

int				sort_a_else(t_param *param, int num)
{
	int			i;
	int			cnt;
	int			r_cnt;
	int			s;
	int			*p;

	cnt = 0;
	r_cnt = 0;
	if (!(p = find_pivot(param->a, num)))
		return (-1);
	i = 0;
	while (i++ < num)
	{
		s = arrange_a(param, p);
		if (s == 0)
			cnt--;
		else if (s == 2)
			r_cnt++;
		cnt++;
		//stack_print(param->a);
		//stack_print(param->b);
	}
	sort_b(param, cnt - r_cnt);
	reverse_rotate_a(param, num - cnt, r_cnt);
	//stack_print(param->a);
	//stack_print(param->b);
	free(p);
	return (cnt);
}

int				sort_b_else(t_param *param, int num)
{
	int			*p;
	int			cnt;
	int			r_cnt;
	int			i;
	int			s;

	cnt = 0;
	r_cnt = 0;
	if (!(p = find_pivot(param->b, num)))
		return (-1);
	i = 0;
	while (i++ < num)
	{
		s = arrange_b(param, p);
		if (s == 0)
			cnt--;
		else if (s == 2)
			r_cnt++;
		cnt++;
		//stack_print(param->a);
		//stack_print(param->b);
	}
	sort_a(param, cnt - r_cnt);
	/*
	s = 0;
	if (size(&param->b) != num - cnt && size(&param->a) != r_cnt)
	{
		for (s = 0; s < num - cnt && s < r_cnt; s++)
			check_command(param, RRR);
	}
	if (size(&param->b) != num - cnt)
	{
		for (int i = s; i < num - cnt; i++)
			check_command(param, RRB);
	}
	if (size(&param->a) != r_cnt)
	{
		for (int i = s; i < r_cnt; i++)
			check_command(param, RRA);
	}
	sort_b(param, num - cnt);
	sort_a(param, r_cnt);
	*/
	reverse_rotate_b(param, num - cnt, r_cnt);
	//stack_print(param->a);
	//stack_print(param->b);
	free(p);
	return (cnt);
}
