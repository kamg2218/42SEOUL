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

typedef struct	s_param
{
	t_stack		*a;
	t_stack		*b;
	int			*pre;
}				t_param;

void	sort_a(t_param *param, int num);
void	sort_b(t_param *param, int num);

//command.c
void	print_command(int cmd);
void	check_else(int* pre, int cmd);
void	do_rotate(t_param *param, int cmd);
void	is_command(t_param *param, int cmd);
void	check_command(t_param *param, int cmd);

//sort_three.c
void	sort_a_three(t_param *param);
void	sort_b_three(t_param *param);
void	sort_a_only_three(t_param *param);
void	sort_b_only_three(t_param *param);

//sort_else.c
int		arrange_a(t_param *param, int *p);
int		arrange_b(t_param *param, int *p);
int		sort_a_else(t_param *param, int num);
int		sort_b_else(t_param *param, int num);
void	reverse_rotatae_a(t_param *param, int cnt, int r_cnt);

//utils.c
//void	stack_print(t_stack*	head);
int		check_a(t_stack* head, int num);
int		check_b(t_stack* head, int num);
void	sort_arr(int *arr, int start, int end);
int		*find_pivot(t_stack *head, int num);

//pre_processing.c
int			check_string(char* c);
int			add_stack(t_stack **tmp, char* str);
size_t		numlen(int num);
t_stack*	parsing(int argc, char* argv[]);
t_stack*	pre_processing(int argc, char* argv[], int** pre);


#endif
