#ifndef CHECKER_H
# define CHECKER_H

# include "../utils/libstack/libstack.h"
# include "../utils/libft.h"
# include "../utils/get_next_line_bonus.h"
# include <stdio.h>
# include <unistd.h>

void	change_arr(int *arr, int i, int pivot);
void	sort_arr(int *arr, int start, int end);
int		*sort(t_stack *head, int num);
int		check(t_stack *head, int *arr, int num);

int		do_rotate(t_stack **a, t_stack **b, char *cmd);
int		is_command(t_stack **a, t_stack **b, char *cmd);
void	do_command(t_stack **a, t_stack **b);

size_t	numlen(int num);
int		check_string(char *c);
int		add_stack(t_stack **tmp, char *str);
t_stack	*parsing(int argc, char *argv[]);
t_stack	*pre_processing(int argc, char *argv[]);

#endif
