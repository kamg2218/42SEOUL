/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rearrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:09:22 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/30 00:00:35 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void	move_forward(t_cmd **start, t_cmd *red, t_cmd *pos)
{
	t_cmd *bef_red;
	t_cmd *aft_red;
	t_cmd *aft_pos;

	bef_red = red->bef;
	aft_red = red->next;
	aft_pos = pos->next;
	if (bef_red)
		bef_red->next = pos;
	pos->bef = bef_red;
	pos->next = red;
	red->bef = pos;
	aft_red->next = aft_pos;
	if (aft_pos != NULL)
		aft_pos->bef = aft_red;
	if (bef_red == NULL)
		*start = pos;
	return ;
}

void	re_arrange(t_cmd **start)
{
	t_cmd *red;
	t_cmd *pos;

	red = NULL;
	pos = *start;
	while (pos)
	{
		if (pos->type == GREAT || pos->type == GREATGREAT || pos->type == LESS)
			red = pos;
		else if (pos->type == PIPE || pos->type == SEMI)
			red = NULL;
		if (red && pos != red && pos != red->next && pos->type == 0)
		{
			move_forward(start, red, pos);
			pos = *start;
			red = NULL;
		}
		else
			pos = pos->next;
	}
}
