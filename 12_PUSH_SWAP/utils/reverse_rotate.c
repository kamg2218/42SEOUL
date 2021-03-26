#include "utils"

void		reverse_rotate(t_node **head, t_node **tail)
{
	t_node	*tmp;

	if (*head == NULL || *tail == NULL)
		return ;
	tmp = *head;
	*head = *head->next;
	tmp->next = NULL;
}
