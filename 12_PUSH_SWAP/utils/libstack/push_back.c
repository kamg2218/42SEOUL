#include "libstack.h"

t_stack			*push_back(t_stack **head, int content)
{
	t_stack		*n;

	if (head == NULL)
		return (NULL);
	n = new(content);
	if (n == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = n;
		n->prev = n;
		n->next = n;
		return (n);
	}
	n->prev = (*head)->prev;
	n->next = *head;
	(*head)->prev->next = n;
	(*head)->prev = n;
	return (n);
}
