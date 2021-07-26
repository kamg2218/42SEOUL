#include "push_swap.h"

int	check_a(t_stack *head, int num)
{
	int		i;
	t_stack	*tmp;

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

int	check_b(t_stack *head, int num)
{
	int		i;
	t_stack	*tmp;

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

void	change_arr(int *arr, int i, int pivot)
{
	int	j;

	j = arr[pivot - 1];
	arr[pivot - 1] = arr[pivot];
	if (i != pivot - 1)
	{
		arr[pivot] = arr[i];
		arr[i] = j;
	}
	else
		arr[pivot] = j;
}

void	sort_arr(int *arr, int start, int end)
{
	int	i;
	int	pivot;

	if (end - start < 1)
		return ;
	pivot = end;
	i = start;
	while (i < pivot)
	{
		if (arr[i] > arr[pivot])
		{
			change_arr(arr, i, pivot);
			pivot--;
		}
		else
			i++;
	}
	sort_arr(arr, 0, pivot - 1);
	sort_arr(arr, pivot + 1, end);
}

int	*find_pivot(t_stack *head, int num)
{
	int		i;
	int		*arr;
	int		*p;
	t_stack	*tmp;

	arr = (int *)malloc(sizeof(int) * (num + 1));
	if (arr == NULL)
		return (NULL);
	p = (int *)malloc(sizeof(int) * 2);
	if (p == NULL)
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
	p[1] = arr[num * 2 / 3];
	free(arr);
	return (p);
}

int		check_dup(t_stack *a, int num)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->content == num)
			return (1);
		tmp = tmp->next;
		if (tmp == a)
			break ;
	}
	return (0);
}
