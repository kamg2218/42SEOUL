/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 00:28:36 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 14:50:49 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			change_inout(t_cmd *tmp)
{
	if (tmp->type == GREATGREAT && redirection(APPEND, tmp))
		return (0);
	else if (tmp->type == GREAT && redirection(TRUNC, tmp))
		return (0);
	else if (tmp->type == LESS && redirection_input(tmp))
		return (0);
	return (1);
}

void		command_line(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_cmd	*head;

	tmp = cmd;
	head = tmp;
	while (tmp && tmp->type != SEMI && g_mini.exit == 0)
	{
		if (g_mini.parent == 0 && tmp->type == PIPE)
			break ;
		if (tmp->type != 0 && tmp->type != PIPE)
		{
			if (change_inout(tmp) == 0)
				return ;
			tmp = tmp->next;
			if (tmp->type == 0)
				tmp = tmp->next;
			continue ;
		}
		if (tmp && tmp->type == PIPE && g_mini.parent)
			return (piping(command_length()));
		tmp = tmp->next;
	}
	if (is_command(head) == 1)
		g_mini.exit = 1;
}

int			main(int argc, char **agrv, char **envp)
{
	argc = 0;
	agrv = NULL;
	drawing_start();
	mini_init();
	g_mini.envp = envp;
	g_mini.env = make_env(envp);
	g_mini.exit = 0;
	while (g_mini.exit != 1)
	{
		while (g_mini.cmd == NULL)
			get_command();
		if (first_command() || last_command())
			continue ;
		check_environ(g_mini.cmd);
		command_line(g_mini.cmd);
		check_last(g_mini.cmd);
		arrange_command(g_mini.cmd);
		ft_close();
	}
	arrange_command(g_mini.cmd);
	ft_varclear(&g_mini.env);
	ft_close();
	return (0);
}
