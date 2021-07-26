#include "push_swap.h"

void	sort_a_only_three(t_param *param)
{
	int	p;

	p = find_pivot(param->a, 3);
	if (param->a->content > p)
		check_command(param, RA);
	else if (!(param->a->content == p && param->a->next->content < p))
		check_command(param, RRA);
	if (param->a->content > param->a->next->content)
		check_command(param, SA);
}

void	sort_b_only_three(t_param *param)
{
	int	p;

	p = find_pivot(param->b, 3);
	if (param->b->content < p)
		check_command(param, RB);
	if (!(param->b->content == p && param->b->next->content > p))
		check_command(param, RRB);
	if (param->b->content < param->b->next->content)
		check_command(param, SB);
}

void	sort_a_three(t_param *param)
{
	int	p;

	if (size(&param->a) == 3)
		return (sort_a_only_three(param));
	p = find_pivot(param->a, 3);
	if (param->a->content > p)
		check_command(param, SA);
	if (!(param->a->content == p && param->a->next->content < p))
	{
		check_command(param, RA);
		check_command(param, SA);
		check_command(param, RRA);
	}
	if (param->a->content > param->a->next->content)
		check_command(param, SA);
}

void	sort_b_three(t_param *param)
{
	int	p;

	if (size(&param->b) == 3)
		return (sort_b_only_three(param));
	p = find_pivot(param->b, 3);
	if (param->b->content < p)
		check_command(param, SB);
	if (!(param->b->content == p && param->b->next->content > p))
	{
		check_command(param, RB);
		check_command(param, SB);
		check_command(param, RRB);
	}
	if (param->b->content < param->b->next->content)
		check_command(param, SB);
}
