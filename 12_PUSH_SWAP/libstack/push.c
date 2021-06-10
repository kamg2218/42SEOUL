#include "libstack.h"

t_stack			*push(t_stack **head, t_stack **tail, int content)
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
		*tail = n;
		return (n);
	}
	*tail->next = n;
	n->prev = *tail;
	*tail = n;
	return (n);
}
