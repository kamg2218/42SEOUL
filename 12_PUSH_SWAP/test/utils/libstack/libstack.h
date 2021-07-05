/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:54:32 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 14:13:45 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTACK_H
# define LIBSTACK_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int					top(t_stack **head);
int					size(t_stack **head);
int					empty(t_stack **head);
void				clear(t_stack **head);
void				swap(t_stack **head);
void				pop(t_stack **head);
void				rotate(t_stack **head);
void				reverse_rotate(t_stack **head);
t_stack				*new(int content);
t_stack				*push(t_stack **head, int content);
t_stack				*push_back(t_stack **head, int content);

#endif
