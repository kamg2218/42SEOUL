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
	tmp = (*head)->prev;
	tmp->prev->next = *head;
	(*head)->prev = tmp->prev;
	tmp->prev = (*head)->prev->prev;
	(*head)->prev->prev->next = tmp;
	tmp->next = (*head)->prev;
	(*head)->prev->prev = tmp;
}
