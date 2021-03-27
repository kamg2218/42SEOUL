#include "libstack.h"

int				size(t_stack **head)
{
	int			count;
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
		return (0);
	count = 1;
	tmp = *head;
	while (tmp->next)
	{
		++count;
		tmp = tmp->next;
	}
	return (count);
}
