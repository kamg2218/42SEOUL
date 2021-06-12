#include "libstack.h"

int			empty(t_stack **head)
{
	if (head == NULL || *head == NULL)
		return (1);
	else
		return (0);
}
