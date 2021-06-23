#include "push_swap.h"

/*
void			stack_print(t_stack *head)
{
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
*/

int				check_a(t_stack *head, int num)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = head->next;
	while (tmp != head && i < num - 1)
	{
		if (tmp->content < tmp->prev->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int				check_b(t_stack *head, int num)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = head->next;
	while (tmp != head && i < num - 1)
	{
		if (tmp->content > tmp->prev->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void		sort_arr(int *arr, int start, int end)
{
	int		i;
	int		j;
	int		pivot;

	if (end - start < 1)
		return ;
	pivot = end;
	i = start;
	while (i < pivot)
	{
		if (arr[i] > arr[pivot])
		{
			j = arr[pivot - 1];
			arr[pivot - 1] = arr[pivot];
			if (i != pivot - 1)
			{
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

int				*find_pivot(t_stack *head, int num)
{
	int			i;
	int			*arr;
	int			*p;
	t_stack*	tmp;

	if (!(arr = (int *)malloc(sizeof(int) * (num + 1))))
		return (NULL);
	if (!(p = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
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
	p[0] = arr[num / 3];
	p[1] = arr[num / 3 * 2];
	free(arr);
	return (p);
}
