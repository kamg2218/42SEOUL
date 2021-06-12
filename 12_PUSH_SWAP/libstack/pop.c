#include "libstack.h"

void			pop(t_stack **head)
{
	t_stack*	tmp;

	if (head == NULL || *head == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	if (tmp == *head)
		*head = NULL;
	else {
		tmp->prev->next = *head;
		(*head)->prev = tmp->prev;
	}
	free(tmp);
}
