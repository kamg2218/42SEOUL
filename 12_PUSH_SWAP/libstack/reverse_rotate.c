#include "libstack.h"

void		reverse_rotate(t_stack **head)
{
	if (head == NULL || *head == NULL)
		return ;
	*head = (*head)->next;
}
