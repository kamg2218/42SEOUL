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

void			reverse_rotate_ab(t_param *param, int cnt, int r_cnt)
{
	int			i;
	int			j;
	int			sa;
	int			sb;

	sa = size(&param->a);
	sb = size(&param->b);
	i = 0;
	while (sa != cnt && sb != r_cnt && i < cnt && i < r_cnt)
	{
		check_command(param, RRR);
		i++;
	}
	j = i;
	while (sa != cnt && j++ < cnt)
		check_command(param, RRA);
	j = i;
	while (sb != r_cnt && j++ < r_cnt)
		check_command(param, RRB);
	sort_a(param, cnt);
	sort_b(param, r_cnt);
}

int				sort_a_else(t_param *param, int num)
{
	int			i;
	int			j;
	int			cnt;
	int			r_cnt;
	int			*p;

	cnt = 0;
	r_cnt = 0;
	if (!(p = find_pivot(param->a, num)))
		return (-1);
	i = 0;
	while (i++ < num)
	{
		j = arrange_a(param, p);
		if (j == 0)
			cnt--;
		else if (j == 2)
			r_cnt++;
		cnt++;
	}
	sort_b(param, cnt - r_cnt);
	reverse_rotate_ab(param, num - cnt, r_cnt);
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
	}
	sort_a(param, cnt - r_cnt);
	reverse_rotate_ab(param, r_cnt, num - cnt);
	free(p);
	return (cnt);
}
