/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:59:00 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/01 20:50:03 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../utils/libstack/libstack.h"
# include "../utils/libft/libft.h"
# include "../utils/get_next_line_bonus.h"
# include <unistd.h>

void	change_arr(int *arr, int i, int pivot);
void	sort_arr(int *arr, int start, int end);
int		*sort(t_stack *head, int num);
int		check(t_stack *head, int *arr, int num);

void	do_rotate(t_stack **a, t_stack **b, char *cmd);
void	is_command(t_stack **a, t_stack **b, char *cmd);

size_t	numlen(int num);
int		check_string(char *c);
int		add_stack(t_stack **tmp, char *str);
t_stack	*parsing(int argc, char *argv[]);
t_stack	*pre_processing(int argc, char *argv[]);

#endif
