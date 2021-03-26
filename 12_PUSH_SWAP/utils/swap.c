#include "utils.h"

void		swap(t_node **head, t_node **tail)
{
	int		tp;
	int		btm;
	t_node	*tmp;

	if (*head == NULL || size(head) < 2)
		return ;
	//tmp = *tail;
	tp = top(head);
	pop(head);
	btm = top(head);
	pop(head);
	push(head, tp);
	push(head, btm);
}
