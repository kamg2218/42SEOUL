#include "push_swap.h"

void		stack_print(t_stack*	head){
	t_stack*	tmp;

	if (head == NULL)
		return ;
	tmp = head;
	printf("%d, ", tmp->content);
	tmp = tmp->next;
	while (tmp != head){
		printf("%d, ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

int		check_a(t_stack* head, int num){
	t_stack*	tmp;
	int			i;

	i = 0;
	tmp = head->next;
	while (tmp != head && i < num - 1){
		if (tmp->content < tmp->prev->content)
			return 0;
		tmp = tmp->next;
		i++;
	}
	return 1;
}

int		check_b(t_stack* head, int num){
	t_stack*	tmp;
	int			i;

	i = 0;
	tmp = head->next;
	while (tmp != head && i < num - 1){
		if (tmp->content > tmp->prev->content)
			return 0;
		tmp = tmp->next;
		i++;
	}
	return 1;
}

void	sort_arr(int *arr, int start, int end)
{
	int		i;
	int		j;
	int		pivot;

	//printf("sort_arr = %d, %d\n", start, end);
	if (end - start < 1)
		return ;
	pivot = end;
	i = start;
	//printf("p = %d\n", pivot);
	while (i < pivot)
	{
		if (arr[i] > arr[pivot])
		{
			j = arr[pivot - 1];
			arr[pivot - 1] = arr[pivot];
			if (i != pivot - 1){
				arr[pivot] = arr[i];
				arr[i] = j;
			}
			else
				arr[pivot] = j;
			pivot--;
		}
		else
			i++;
	}
	sort_arr(arr, 0, pivot - 1);
	sort_arr(arr, pivot + 1, end);
}

void		find_pivot(t_stack* head, int num, int *p1, int *p2){
	int			i;
	int			*arr;
	t_stack*	tmp;

	if (!(arr = (int *)malloc(sizeof(int) * (num + 1))))
		return ;
	i = 0;
	tmp = head;
	while (i < num)
	{
		arr[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	arr[i] = 0;
	sort_arr(arr, 0, num - 1);
	if (num / 3 == 0)
	{
		*p1 = arr[num / 3 - 1];
		*p2 = arr[num / 3 * 2 - 1];
	}
	else
	{
		*p1 = arr[num / 3];
		*p2 = arr[num / 3 * 2];
	}
	free(arr);
}
