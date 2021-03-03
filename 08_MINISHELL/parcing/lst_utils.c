/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:09:02 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/30 16:55:53 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void	ft_lstmerge(t_cmd *bef, t_cmd *aft)
{
	t_cmd *pos;

	pos = bef;
	while (pos->next)
		pos = pos->next;
	pos->next = aft;
	aft->bef = pos;
	return ;
}

t_cmd	*ft_lst_start(char *str, int type)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (cmd == NULL)
		malloc_error();
	cmd->str = str;
	cmd->type = type;
	cmd->next = NULL;
	cmd->bef = NULL;
	return (cmd);
}

void	ft_lstadd(t_cmd *start, char *str, int type)
{
	t_cmd	*pos;
	t_cmd	*new;

	if (start == NULL)
		return ;
	new = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (new == NULL)
		malloc_error();
	pos = start;
	while (pos->next)
		pos = pos->next;
	new->str = str;
	new->type = type;
	new->next = NULL;
	new->bef = pos;
	pos->next = new;
	return ;
}

void	free_cmd(t_cmd *start)
{
	t_cmd	*pos;
	t_cmd	*bef;

	pos = start;
	while (pos)
	{
		if (pos->str)
			free(pos->str);
		bef = pos;
		pos = pos->next;
		free(bef);
	}
	return ;
}
