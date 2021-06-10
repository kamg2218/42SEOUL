#include "libstack.h"

int			top(t_stack **head, t_stack **tail)
{
	if (head == NULL || *head == NULL || tail == NULL)
		return (NULL);
	return (*tail->content);
}
