/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 00:28:14 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 02:38:15 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		mini_init(void)
{
	g_mini.exit = 0;
	g_mini.cmd = NULL;
	g_mini.tmpin = dup(0);
	g_mini.tmpout = dup(1);
	g_mini.fdin = dup(0);
	g_mini.fdout = dup(1);
	g_mini.file = 0;
	g_mini.pipe = 0;
	g_mini.signal = 0;
	g_mini.sigint = 0;
	g_mini.parent = 1;
	g_mini.envp = NULL;
}

void		ft_close(void)
{
	if (g_mini.fdin > 1)
		close(g_mini.fdin);
	if (g_mini.fdout > 1)
		close(g_mini.fdout);
	close(STDOUT);
	close(STDIN);
	dup2(g_mini.tmpin, STDIN);
	dup2(g_mini.tmpout, STDOUT);
	dup2(g_mini.tmpin, g_mini.fdin);
	dup2(g_mini.tmpout, g_mini.fdout);
	g_mini.pipe = 0;
	g_mini.sigint = 0;
	g_mini.file = 0;
	g_mini.parent = 1;
}

int			is_last_cmd(t_cmd *start)
{
	t_cmd	*tmp;

	tmp = start;
	while (start && start->type != SEMI)
	{
		if (start->type == PIPE)
			return (0);
		start = start->next;
	}
	return (1);
}
