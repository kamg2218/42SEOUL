#include "push_swap.h"

void		is_command(t_stack** a, t_stack** b, int cmd)
{
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
	else
		do_rotate(a, b, cmd);
}

void	do_rotate(t_stack**a, t_stack** b, int cmd)
{
	if (cmd == RA)
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

void		print_command(int cmd)
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

void	check_command(t_stack** a, t_stack** b, int* pre, int cmd)
{
	is_command(a, b, cmd);
	if (pre[0] == 0)
	{
		pre[0] = cmd;
		pre[1] = 1;
		return ;
	}
	else if (pre[0] == cmd)
	{
		pre[1] += 1;
		return ;
	}
	else if ((pre[0] == SA && cmd == SB) || (pre[0] == SB && cmd == SA))
		print_command(SS);
	else if ((pre[0] == RA && cmd == RB) || (pre[0] == RB && cmd == RA))
		print_command(RR);
	else if ((pre[0] == PA && cmd == PB) || (pre[0] == PB && cmd == PA))
		print_command(0);
	else if ((pre[0] == RRA && cmd == RRB) || (pre[0] == RRB && cmd == RRA))
		print_command(RRR);
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
