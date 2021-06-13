#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../utils/libstack/libstack.h"
#include "../utils/libft.h"
#include "../utils/get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>

void	sort_arr(int *arr, int start, int end);
int*	sort(t_stack* head, int num);
int		check(t_stack* head, int *arr, int num);
char*	is_command(t_stack** a, t_stack** b, char* str);

#endif
