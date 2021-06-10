#include "utils.h"

void		rotate(t_node **head, t_node **tail)
{
	t_node	*tmp;

	if (head == NULL || *head == NULL || tail == NULL)
		return ;
	if (*head == *tail)
		return ;
	tmp = tail;
	*tail = tail->prev;
	*tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = *head;
	*head->prev = tmp;
	*head = tmp;
}
