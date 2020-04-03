void	swap(int *a, int *b);
void	set_1234(int *a);

int		next_permutation(int *a, int n)
{
	int		i;
	int		j;

	if (a[0] == 0)
	{
		set_1234(a);
		return (1);
	}
	i = n - 1;
	j = n - 1;
	while (i > 0 && a[i - 1] >= a[i])
		i -= 1;
	if (i <= 0)
		return (0);
	while (a[i - 1] >= a[j])
		j -= 1;
	swap(&a[i - 1], &a[j]);
	j = n - 1;
	while (i < j)
	{
		swap(&a[i], &a[j]);
		i += 1;
		j -= 1;
	}
	return (1);
}

void	swap(int *a, int *b)
{
	int		temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void	set_1234(int *a)
{
	int		i;

	i = -1;
	while (++i < 16)
		a[i] = i % 4 + 1;
}
