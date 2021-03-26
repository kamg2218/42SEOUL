#include "libstack.h"

void			*top(t_stack **head)
{
	void		*cont;
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
		return (NULL);
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	cont = tmp->content;
	return (cont);
}
