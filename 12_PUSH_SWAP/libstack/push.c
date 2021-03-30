#include "libstack.h"

t_stack			*push(t_stack **head, void *content)
{
	t_stack		*n;
	t_stack		*tmp;

	if (head == NULL)
		return (NULL);
	n = new(content);
	if (n == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = n;
		return (n);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = n;
	n->next = NULL;
	return (n);
}
