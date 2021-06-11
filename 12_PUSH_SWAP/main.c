#include "libstack/libstack.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void		print(t_stack*	head){
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

int		check(t_stack* head){
	t_stack*	tmp;

	tmp = head->prev;
	while (tmp != head){
		if (tmp->content > tmp->prev->content)
			return 0;
		tmp = tmp->prev;
	}
	return 1;
}

char*		is_command(t_stack** a, t_stack** b, char* str){
	if (!(ft_strncmp("sa", str, 3)))
		swap(a);
	else if (!(ft_strncmp("sb", str, 3)))
		swap(b);
	else if (!(ft_strncmp("ss", str, 3))){
		swap(a);
		swap(b);
	}
	else if (!(ft_strncmp("pa", str, 3))){
		push(a, top(b));
		pop(b);
	}
	else if (!(ft_strncmp("pb", str, 3))){
		push(b, top(a));
		pop(a);
	}
	else if (!(ft_strncmp("ra", str, 3)))
		rotate(a);
	else if (!(ft_strncmp("rb", str, 3)))
		rotate(b);
	else if (!(ft_strncmp("rr", str, 3))){
		rotate(a);
		rotate(b);
	}
	else if (!(ft_strncmp("rra", str, 3)))
		reverse_rotate(a);
	else if (!(ft_strncmp("rrb", str, 3)))
		reverse_rotate(b);
	else if (!(ft_strncmp("rrr", str, 3))){
		reverse_rotate(a);
		reverse_rotate(b);
	}
	return str;
}

void	quicksort(t_stack** a, t_stack** b)
{
	int			pivot;
	t_stack*	tmp;
	t_stack*	c;

	if (check(*a))
		return ;
	tmp = *a;
	pivot = tmp->content;
	c = (*a)->prev;
	while (tmp != c){
		if (c->prev != tmp
				&& (c->prev->content > pivot && c->prev->content < c->content
				|| c->prev->content <= pivot && c->prev->content > c->content))
			printf("%s\n", is_command(a, b, "sa"));
		if (check(*a))
			return ;
		if (c->content > pivot){
			if ((*a)->content > top(a)){
				printf("%s\n", is_command(a, b, "rra"));
				printf("%s\n", is_command(a, b, "sa"));
				printf("%s\n", is_command(a, b, "ra"));
			}
			printf("%s\n", is_command(a, b, "ra"));
		}
		else{
			printf("%s\n", is_command(a, b, "pb"));
			if (top(b) > top(a))
				printf("%s\n", is_command(a, b, "sb"));
		}
		c = (*a)->prev;
	}
}

int			main(int argc, char* argv[])
{
	int			i;
	t_stack*	a = 0;
	t_stack*	b = 0;
	char		cmd[4] = {0, };

	printf("argc = %d\n", argc);
	if (argc < 2){
		printf("Input Error\n");
		return -1;
	}
	for (i = 1; i < argc; i++)
		push_back(&a, ft_atoi(argv[i]));
	/*
	while (1)
	{
		scanf("%s", cmd);
		getchar();
		is_command(&a, &b, cmd);
		print(a);
		print(b);
	}
	*/
	quicksort(&a, &b);
	print(a);
	print(b);
	clear(&a);
	clear(&b);
	return 0;
}
