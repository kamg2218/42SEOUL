#include "libft.h"
#include "libstack/libstack.h"

void	quicksort(t_stack** a, t_stack** b)
{
	int			pivot;
	t_stack*	tmp;

	tmp = *a;
	pivot = tmp->content;
	//printf("%s\n", is_command(a, b, "ra"));
	//tmp = tmp->prev;
	while (tmp != (*a)->prev){
		if ((*a)->prev->content > pivot){
			printf("%s\n", is_command(a, b, "ra"));
		}
		else{
			printf("%s\n", is_command(a, b, "pb"));
		}
	}
}
