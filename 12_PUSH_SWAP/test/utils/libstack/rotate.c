#include "libstack.h"

void	rotate(t_stack **head)
{
	if (head == NULL || *head == NULL)
		return ;
	*head = (*head)->next;
}
