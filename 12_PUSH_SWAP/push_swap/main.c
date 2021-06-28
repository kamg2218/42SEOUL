#include "push_swap.h"

void			sort_a(t_param *param, int num)
{
	int			i;
	int			cnt;

	if (num < 2)
		return ;
	else if (check_a(param->a, num))
		return ;
	else if (num == 2)
	{
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

int				main(int argc, char *argv[])
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
	return (0);
}
