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

int	check_else(int n, int cmd)
{
	if ((n == SA && cmd == SB) || (n == SB && cmd == SA))
		return SS;
	else if ((n == RA && cmd == RB) || (n == RB && cmd == RA))
		return RR;
	else if ((n == RRA && cmd == RRB) || (n == RRB && cmd == RRA))
		return RRR;
	else if ((n == PA && cmd == PB) || (n == PB && cmd == PA)
		|| (n == RA && cmd == RRA) || (n == RRA && cmd == RA)
		|| (n == RB && cmd == RRB) || (n == RRB && cmd == RB)
		|| (n == SA && cmd == SA) || (n == SB && cmd == SB)
		|| (n == SS && cmd == SS) || (n == RR && cmd == RRR))
		return -1;
	return 0;
}

void	check_command(t_param *param, int cmd)
{
	int		n;
	int		*tmp;

	is_command(param, cmd);
	n = 0;
	if (param->size > 0)
		n = check_else(param->cmd[param->size - 1], cmd);
	if (n == -1)
	{
		param->size -= 1;
		param->cmd[param->size] = 0;
	}
	else if (n)
		param->cmd[param->size - 1] = n;
	else
	{
		if (param->size == param->cap)
		{
			tmp = ft_calloc(4, param->cap * 2);
			n = 0;
			while (n < param->size)
			{
				tmp[n] = param->cmd[n];
				n++;
			}
			param->cap = param->cap * 2;
			free(param->cmd);
			param->cmd = tmp;
		}
		param->cmd[param->size] = cmd;
		param->size += 1;
	}
}

void	move_command(t_param *param, int start)
{
	int		i;

	i = start;
	while (i < param->size)
	{
		param->cmd[i] = param->cmd[i + 1];
		i++;
	}
	param->cmd[i] = 0;
	param->size -= 1;
}

void	arrange_command(t_param *param)
{
	int	i;
	int	n;

	i = param->size - 1;
	while (--i >= 0)
	{
		n = check_else(param->cmd[i], param->cmd[i + 1]);
		if (n == 0)
			continue ;
		if (n == -1)
		{
			move_command(param, i + 1);
			move_command(param, i);
		}
		else if (n)
		{
			param->cmd[i] = n;
			move_command(param, i + 1);
		}
		i++;
	}
}
