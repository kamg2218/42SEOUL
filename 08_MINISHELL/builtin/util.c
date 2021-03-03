/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 00:28:14 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 04:21:37 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			command_length(void)
{
	int		len;
	t_cmd	*tmp;

	tmp = g_mini.cmd;
	if (tmp == NULL)
		return (0);
	len = 0;
	while (tmp && tmp->type != SEMI)
	{
		tmp = tmp->next;
		++len;
	}
	return (len);
}

t_cmd		*clear_cmd(t_cmd *head, t_cmd *tmp)
{
	t_cmd	*pre;

	pre = tmp;
	tmp = tmp->next;
	if (head)
		head->next = tmp;
	else
		g_mini.cmd = tmp;
	if (tmp)
		tmp->bef = head;
	if (pre->str)
		free(pre->str);
	free(pre);
	return (tmp);
}

void		arrange_command(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_cmd	*head;

	head = NULL;
	tmp = cmd;
	if (tmp && tmp->bef)
		head = tmp->bef;
	while (tmp && tmp->type != SEMI)
		tmp = clear_cmd(head, tmp);
	if (tmp)
		tmp = clear_cmd(head, tmp);
	if (tmp == NULL)
		g_mini.cmd = NULL;
}

int			first_command(void)
{
	t_cmd	*tmp;

	if ((g_mini.cmd->str)[0] == 0 && g_mini.cmd->next)
	{
		tmp = g_mini.cmd;
		g_mini.cmd = tmp->next;
		g_mini.cmd->bef = NULL;
		free(tmp->str);
		free(tmp);
	}
	tmp = g_mini.cmd;
	if (tmp->type == PIPE || tmp->type == SEMI)
	{
		syntax_error(tmp->str);
		arrange_command(g_mini.cmd);
		return (1);
	}
	return (0);
}

int			last_command(void)
{
	int		i;
	int		len;
	t_cmd	*tmp;
	t_cmd	*head;

	tmp = g_mini.cmd;
	head = tmp;
	if ((len = command_length()) <= 0)
		return (0);
	i = -1;
	while (++i < len - 1)
	{
		if (tmp->type == PIPE || tmp->type == SEMI)
			head = tmp;
		tmp = tmp->next;
	}
	if (!(ft_strncmp(tmp->str, "", 1)) && tmp->bef)
		tmp = tmp->bef;
	if (tmp->type == PIPE)
	{
		syntax_error("\'|\'");
		arrange_command(g_mini.cmd);
		return (1);
	}
	return (0);
}
