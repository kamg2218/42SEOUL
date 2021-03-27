#include "libstack.h"

void			pop(t_stack **head)
{
	t_stack		*prev;
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
		return ;
	tmp = *head;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		prev->next = NULL;
	else
		*head = NULL;
	free(tmp);
}
