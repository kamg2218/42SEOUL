#include "utils.h"

void		rotate(t_node **head, t_node **tail)
{
	t_node	*tmp;

	if (*head == NULL || *tail == NULL)
		return ;
	tmp = (t_node *)malloc(sizeof(t_node) * 1);
	if (tmp == NULL)
		return ;
	tmp->content = top(head);
	pop(head);
	tmp->next = *head;
	*head = tmp;
}
