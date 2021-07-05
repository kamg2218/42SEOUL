/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:00:29 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 13:31:15 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_only_three(t_param *param)
{
	int		*p;

	p = find_pivot(param->a, 3);
	if (param->a->content == p[1])
		check_command(param, RA);
	else if (!(param->a->content == p[0] && param->a->next->content < p[0]))
		check_command(param, RRA);
	if (param->a->content > param->a->next->content)
		check_command(param, SA);
	free(p);
}

void	sort_b_only_three(t_param *param)
{
	int		*p;

	p = find_pivot(param->b, 3);
	if (param->b->content != p[0] && param->b->content != p[1])
		check_command(param, RB);
	if (!(param->b->content == p[0] && param->b->next->content > p[0]))
		check_command(param, RRB);
	if (param->b->content < param->b->next->content)
		check_command(param, SB);
	free(p);
}

void	sort_a_three(t_param *param)
{
	int		*p;

	if (size(&param->a) == 3)
		return (sort_a_only_three(param));
	p = find_pivot(param->a, 3);
	if (param->a->content == p[1])
		check_command(param, SA);
	if (!(param->a->content == p[0] && param->a->next->content < p[0]))
	{
		check_command(param, RA);
		check_command(param, SA);
		check_command(param, RRA);
	}
	if (param->a->content > param->a->next->content)
		check_command(param, SA);
	free(p);
}

void	sort_b_three(t_param *param)
{
	int		*p;

	if (size(&param->b) == 3)
		return (sort_b_only_three(param));
	p = find_pivot(param->b, 3);
	if (param->b->content != p[0] && param->b->content != p[1])
		check_command(param, SB);
	if (!(param->b->content == p[0] && param->b->next->content > p[0]))
	{
		check_command(param, RB);
		check_command(param, SB);
		check_command(param, RRB);
	}
	if (param->b->content < param->b->next->content)
		check_command(param, SB);
	free(p);
}
