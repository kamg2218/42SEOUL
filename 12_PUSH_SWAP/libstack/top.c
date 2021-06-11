#include "libstack.h"

int			top(t_stack **head)
{
	return ((*head)->prev->content);
}
