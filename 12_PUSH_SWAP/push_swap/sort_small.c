#include "push_swap.h"

int		sort_a_small(t_stack** a, t_stack** b, int *pre, int num)
{
	int		i;
	int		s;
	int		p1;
	int		p2;
	int		cnt;

	find_pivot(*a, num, &p1, &p2);
	s = size(a);
	i = 0;
	cnt = 0;
	for (i = 0; i < num; i++)
	{
		if ((*a)->content >= p1)
		{
			//if ((*a)->next->content >= p1
			//		&& (*a)->content > (*a)->next->content && i != num - 1)
			//	check_command(a, b, pre, SA);
			//if (check_a(*a, num) && (*a)->content >= p1)
			//	break ;
			check_command(a, b, pre, RA);
		}
		else
		{
			//if ((*a)->next->content < p1
			//		&& (*a)->content > (*a)->next->content && i != num - 1)
			//	check_command(a, b, pre, SA);
			//if (check_a(*a, num) && (*a)->content >= p1)
			//	break ;
			check_command(a, b, pre, PB);
			cnt++;
		}
	}
	sort_b(a, b, pre, cnt);
	if (s != num)
	{
		for (i = 0; i < num - cnt; i++)
			check_command(a, b, pre, RRA);
	}
	sort_a(a, b, pre, num - cnt);
	return (cnt);
}
