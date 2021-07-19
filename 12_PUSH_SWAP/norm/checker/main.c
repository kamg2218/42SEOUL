#include "checker.h"

int	check(t_stack *head, int *arr, int num)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = head;
	while (tmp != head->prev && i < num)
	{
		if (tmp->content != arr[i])
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

int	*sort(t_stack *head, int num)
{
	int		i;
	int		*arr;
	t_stack	*tmp;

	arr = (int *)malloc(sizeof(int) * (num + 1));
	if (arr == NULL)
		return (0);
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
	return (arr);
}

int	main(int argc, char *argv[])
{
	int		*arr;
	t_stack	*a;
	t_stack	*b;

	a = pre_processing(argc, argv);
	if (a == NULL)
		return (-1);
	b = 0;
	arr = sort(a, size(&a));
	if (!(do_command(&a, &b)))
	{
		if ((check(a, arr, size(&a))))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	clear(&a);
	clear(&b);
	free(arr);
	return (0);
}
