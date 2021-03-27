#include "libstack.h"

void			push(t_stack **head, void *content)
{
	t_stack		*n;
	t_stack		*tmp;

	if (!(n = new(content)))
		return ;
	if (head == NULL || *head == NULL)
	{
		*head = n;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = n;
	n->next = NULL;
}
