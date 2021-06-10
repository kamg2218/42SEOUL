#include "libstack.h"

void			pop(t_stack **head, t_stack **tail)
{
	t_stack*	tmp;

	if (head == NULL || *head == NULL || tail == NULL)
		return ;
	tmp = *tail;
	*tail = tmp->prev;
	*tail->next = NULL;
	if (tmp == head)
		*head = NULL;
	free(tmp);
}
