#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../utils/libstack/libstack.h"
#include "../utils/libft.h"
#include <stdio.h>
#include <unistd.h>

# define SA		1
# define SB		2
# define SS		3
# define PA		4
# define PB		5
# define RA		6
# define RB		7
# define RR		8
# define RRA	9
# define RRB	10
# define RRR	11

int		check_a(t_stack* head, int num);
int		check_b(t_stack* head, int num);
int		sort_a_else(t_stack** a, t_stack** b, int* pre, int num);
int		sort_b_else(t_stack** a, t_stack** b, int* pre, int num);
int		sort_a_small(t_stack** a, t_stack** b, int* pre, int num);

//command.c
void	print_command(int cmd);
void	do_rotate(t_stack** a, t_stack** b, int cmd);
void	is_command(t_stack** a, t_stack** b, int cmd);
int		check_command(t_stack** a, t_stack** b, int pre, int cmd);

//sort_three.c
void	sort_a_three(t_stack** a, t_stack** b, int* pre);
void	sort_b_three(t_stack** a, t_stack** b, int* pre);
void	sort_a_only_three(t_stack** a, t_stack** b, int* pre);
void	sort_b_only_three(t_stack** a, t_stack** b, int* pre);

//utils.c
void	stack_print(t_stack*	head);
void	sort_arr(int *arr, int start, int end);
void	sort_a(t_stack** a, t_stack** b, int* pre, int num);
void	sort_b(t_stack** a, t_stack** b, int* pre, int num);
void	find_pivot(t_stack* head, int num, int *p1, int *p2);

#endif
