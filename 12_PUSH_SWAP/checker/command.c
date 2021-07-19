/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:59:19 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/19 18:30:54 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_command(t_stack **a, t_stack **b, char *cmd)
{
	if (!(ft_strncmp(cmd, "sa", 3)) && size(a) > 1)
		swap(a);
	else if (!(ft_strncmp(cmd, "sb", 3)) && size(b) > 1)
		swap(b);
	else if (!(ft_strncmp(cmd, "ss", 3)) && size(a) > 1 && size(b) > 1)
	{
		swap(a);
		swap(b);
	}
	else if (!(ft_strncmp(cmd, "pa", 3)) && !empty(b))
	{
		push(a, top(b));
		pop(b);
	}
	else if (!(ft_strncmp(cmd, "pb", 3)) && !empty(a))
	{
		push(b, top(a));
		pop(a);
	}
	else
		return (do_rotate(a, b, cmd));
	return (0);
}

int		do_rotate(t_stack **a, t_stack **b, char *cmd)
{
	if (!(ft_strncmp(cmd, "ra", 3)) && !empty(a))
		rotate(a);
	else if (!(ft_strncmp(cmd, "rb", 3)) && !empty(b))
		rotate(b);
	else if (!(ft_strncmp(cmd, "rr", 3)) && !empty(a) && !empty(b))
	{
		rotate(a);
		rotate(b);
	}
	else if (!(ft_strncmp(cmd, "rra", 4)) && !empty(a))
		reverse_rotate(a);
	else if (!(ft_strncmp(cmd, "rrb", 4)) && !empty(b))
		reverse_rotate(b);
	else if (!(ft_strncmp(cmd, "rrr", 4)) && !empty(a) && !empty(b))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (1);
	return (0);
}

int	do_command(t_stack **a, t_stack **b)
{
	int		re;
	char	*cmd;

	while (1)
	{
		re = get_next_line(0, &cmd);
		if (re == -1)
			return (0);
		else if (re)
		{
			if (is_command(a, b, cmd))
			{
				write(1, "ERROR\n", 6);
				free(cmd);
				return (1);
			}
		}
		free(cmd);
	}
	return (0);
}
