#include "libstack.h"

void		swap(t_stack **head)
{
	t_stack		*tmp;

	if (*head == NULL || size(head) < 2)
		return ;
	if (size(head) == 2){
		*head = (*head)->next;
		return ;
	}
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next->prev = *head;
	tmp->prev = (*head)->prev;
	(*head)->prev->next = tmp;
	tmp->next = *head;
	(*head)->prev = tmp;
	*head = tmp;
}
