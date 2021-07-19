#include "push_swap.h"

void	is_command(t_param *param, int cmd)
{
	if (cmd == SA)
		swap(&param->a);
	else if (cmd == SB)
		swap(&param->b);
	else if (cmd == SS)
	{
		swap(&param->a);
		swap(&param->b);
	}
	else if (cmd == PA)
	{
		push(&param->a, top(&param->b));
		pop(&param->b);
	}
	else if (cmd == PB)
	{
		push(&param->b, top(&param->a));
		pop(&param->a);
	}
	else
		do_rotate(param, cmd);
}

void	do_rotate(t_param *param, int cmd)
{
	if (cmd == RA)
		rotate(&param->a);
	else if (cmd == RB)
		rotate(&param->b);
	else if (cmd == RR)
	{
		rotate(&param->a);
		rotate(&param->b);
	}
	else if (cmd == RRA)
		reverse_rotate(&param->a);
	else if (cmd == RRB)
		reverse_rotate(&param->b);
	else if (cmd == RRR)
	{
		reverse_rotate(&param->a);
		reverse_rotate(&param->b);
	}
}

void	print_command(int cmd)
{
	if (cmd == SA)
		ft_putstr_fd("sa\n", 1);
	else if (cmd == SB)
		ft_putstr_fd("sb\n", 1);
	else if (cmd == SS)
		ft_putstr_fd("ss\n", 1);
	else if (cmd == PA)
		ft_putstr_fd("pa\n", 1);
	else if (cmd == PB)
		ft_putstr_fd("pb\n", 1);
	else if (cmd == RA)
		ft_putstr_fd("ra\n", 1);
	else if (cmd == RB)
		ft_putstr_fd("rb\n", 1);
	else if (cmd == RR)
		ft_putstr_fd("rr\n", 1);
	else if (cmd == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (cmd == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (cmd == RRR)
		ft_putstr_fd("rrr\n", 1);
}

void	check_else(int *pre, int cmd)
{
	if ((pre[0] == SA && cmd == SB) || (pre[0] == SB && cmd == SA))
		print_command(SS);
	else if ((pre[0] == RA && cmd == RB) || (pre[0] == RB && cmd == RA))
		print_command(RR);
	else if ((pre[0] == RRA && cmd == RRB) || (pre[0] == RRB && cmd == RRA))
		print_command(RRR);
	else if ((pre[0] == PA && cmd == PB) || (pre[0] == PB && cmd == PA)
		|| (pre[0] == RA && cmd == RRA) || (pre[0] == RRA && cmd == RA)
		|| (pre[0] == RB && cmd == RRB) || (pre[0] == RRB && cmd == RB))
		print_command(0);
	else
	{
		while (pre[1] > 0)
		{
			print_command(pre[0]);
			pre[1] -= 1;
		}
		pre[0] = cmd;
		pre[1] = 1;
		return ;
	}
	pre[1] -= 1;
	if (pre[1] == 0)
		pre[0] = 0;
}

void	check_command(t_param *param, int cmd)
{
	is_command(param, cmd);
	if (param->pre[0] == 0)
	{
		param->pre[0] = cmd;
		param->pre[1] = 1;
	}
	else if (param->pre[0] == cmd)
		param->pre[1] += 1;
	else
		check_else(param->pre, cmd);
}
