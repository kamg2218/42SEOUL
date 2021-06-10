#include "libstack.h"

t_stack		*new(int content)
{
	t_stack	*n;

	n = (t_stack *)malloc(sizeof(t_stack));
	if (n == NULL)
		return (NULL);
	n->content = content;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}
