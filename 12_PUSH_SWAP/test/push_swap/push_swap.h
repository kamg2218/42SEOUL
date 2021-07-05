/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:00:44 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 13:31:49 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../utils/libstack/libstack.h"
# include "../utils/libft/libft.h"
# include <unistd.h>

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

typedef struct s_param
{
	t_stack		*a;
	t_stack		*b;
	int			*pre;
}				t_param;

void			sort_a(t_param *param, int num);
void			sort_b(t_param *param, int num);

void			print_command(int cmd);
void			check_else(int *pre, int cmd);
void			do_rotate(t_param *param, int cmd);
void			is_command(t_param *param, int cmd);
void			check_command(t_param *param, int cmd);

void			sort_a_three(t_param *param);
void			sort_b_three(t_param *param);
void			sort_a_only_three(t_param *param);
void			sort_b_only_three(t_param *param);

int				arrange_a(t_param *param, int *p);
int				arrange_b(t_param *param, int *p);
int				sort_a_else(t_param *param, int num);
int				sort_b_else(t_param *param, int num);
void			reverse_rotatae_ab(t_param *param, int cnt, int r_cnt);

int				check_a(t_stack *head, int num);
int				check_b(t_stack *head, int num);
int				*find_pivot(t_stack *head, int num);
void			change_arr(int *arr, int i, int pivot);
void			sort_arr(int *arr, int start, int end);

int				check_string(char *c);
int				add_stack(t_stack **tmp, char *str);
size_t			numlen(int num);
t_stack			*parsing(int argc, char *argv[]);
t_stack			*pre_processing(int argc, char *argv[], int **pre);

#endif
