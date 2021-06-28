#include "checker.h"

void		is_command(t_stack **a, t_stack **b, char *cmd)
{
	if (!(ft_strncmp(cmd, "sa", 3)))
		swap(a);
	else if (!(ft_strncmp(cmd, "sb", 3)))
		swap(b);
	else if (!(ft_strncmp(cmd, "ss", 3)))
	{
		swap(a);
		swap(b);
	}
	else if (!(ft_strncmp(cmd, "pa", 3)))
	{
		push(a, top(b));
		pop(b);
	}
	else if (!(ft_strncmp(cmd, "pb", 3)))
	{
		push(b, top(a));
		pop(a);
	}
	else
		do_rotate(a, b, cmd);
}

void		do_rotate(t_stack **a, t_stack **b, char *cmd)
{
	if (!(ft_strncmp(cmd, "ra", 3)))
		rotate(a);
	else if (!(ft_strncmp(cmd, "rb", 3)))
		rotate(b);
	else if (!(ft_strncmp(cmd, "rr", 3)))
	{
		rotate(a);
		rotate(b);
	}
	else if (!(ft_strncmp(cmd, "rra", 4)))
		reverse_rotate(a);
	else if (!(ft_strncmp(cmd, "rrb", 4)))
		reverse_rotate(b);
	else if (!(ft_strncmp(cmd, "rrr", 4)))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}
