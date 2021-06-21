#include "push_swap.h"

void	sort_a_only_three(t_stack **a, t_stack **b, int* pre)
{
	int		p1;
	int		p2;

	find_pivot(*a, 3, &p1, &p2);
	if ((*a)->content == p2)
		check_command(a, b, pre, RA);
	else if (!((*a)->content == p1 && (*a)->next->content < p1))
		check_command(a, b, pre, RRA);
	if ((*a)->content > (*a)->next->content)
		check_command(a, b, pre, SA);
}

void	sort_b_only_three(t_stack **a, t_stack **b, int* pre)
{
	int		p1;
	int		p2;

	find_pivot(*b, 3, &p1, &p2);
	if ((*b)->content != p1 && (*b)->content != p2)
		check_command(a, b, pre, RB);
	if (!((*b)->content == p1 && (*b)->next->content > p1))
		check_command(a, b, pre, RRB);
	if ((*b)->content < (*b)->next->content)
		check_command(a, b, pre, SB);
}

void	sort_a_three(t_stack **a, t_stack **b, int* pre)
{
	int		p1;
	int		p2;

	if (size(a) == 3)
		return (sort_a_only_three(a, b, pre));
	find_pivot(*a, 3, &p1, &p2);
	if ((*a)->content == p2)
		check_command(a, b, pre, SA);
	if (!((*a)->content == p1 && (*a)->next->content < p1))
	{
		check_command(a, b, pre, RA);
		check_command(a, b, pre, SA);
		check_command(a, b, pre, RRA);
	}
	if ((*a)->content > (*a)->next->content)
		check_command(a, b, pre, SA);
}

void	sort_b_three(t_stack **a, t_stack **b, int* pre)
{
	int		p1;
	int		p2;

	if (size(b) == 3)
		return (sort_b_only_three(a, b, pre));
	find_pivot(*b, 3, &p1, &p2);
	if ((*b)->content != p1 && (*b)->content != p2)
		check_command(a, b, pre, SB);
	if (!((*b)->content == p1 && (*b)->next->content > p1))
	{
		check_command(a, b, pre, RB);
		check_command(a, b, pre, SB);
		check_command(a, b, pre, RRB);
	}
	if ((*b)->content < (*b)->next->content)
		check_command(a, b, pre, SB);
}
