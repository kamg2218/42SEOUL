#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../utils/libstack/libstack.h"
#include "../utils/libft.h"
#include <stdio.h>
#include <unistd.h>

void	stack_print(t_stack*	head);
void	sort_arr(int *arr, int start, int end);
void	sort_a(t_stack** a, t_stack** b, int num);
void	sort_b(t_stack** a, t_stack** b, int num);
void	sort_a_three(t_stack** a, t_stack** b);
void	sort_b_three(t_stack** a, t_stack** b);
int		check_a(t_stack* head, int num);
int		check_b(t_stack* head, int num);
int		find_pivot(t_stack* head, int num);
int		sort_a_else(t_stack** a, t_stack** b, int num);
int		sort_b_else(t_stack** a, t_stack** b, int num);
char*	is_command(t_stack** a, t_stack** b, char* str);

#endif
