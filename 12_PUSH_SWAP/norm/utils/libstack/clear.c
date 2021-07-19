#include "libstack.h"

void	clear(t_stack **head)
{
	t_stack	*pre;
	t_stack	*tmp;

	if (head == NULL || *head == NULL)
		return ;
	tmp = *head;
	tmp->prev->next = NULL;
	while (tmp)
	{
		pre = tmp;
		tmp = tmp->next;
		free(pre);
	}
}
