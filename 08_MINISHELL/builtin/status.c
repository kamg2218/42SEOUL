/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 23:13:16 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 16:32:11 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		set_status(int status)
{
	if (status == 13)
		g_mini.signal = 127;
	else if (status == 0)
		g_mini.signal = 0;
	else if (status > 128)
		g_mini.signal = status / 256;
	else
		g_mini.signal = status + 128;
}

void		check_last(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_cmd	*head;

	if (g_mini.parent == 0
			|| (g_mini.cmd->str[0] == 0 && g_mini.cmd->next == NULL))
		return ;
	tmp = cmd;
	head = cmd;
	while (tmp && tmp->type != SEMI)
	{
		if (tmp->type == PIPE)
			head = tmp->next;
		tmp = tmp->next;
	}
	if (head && head->str && !(ft_strncmp("grep", head->str, 5)))
	{
		if (head->next == NULL || head->next->type == SEMI
			|| (head->next && head->next->str[0] == 0))
			g_mini.signal = 2;
	}
	else if (head && head->str && check_strncmp(head->str, head->str) == 0
				&& is_builtin(head->str) == 0)
		g_mini.signal = 127;
}
