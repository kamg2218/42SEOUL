/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:42:28 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 04:04:43 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			redirection(int type, t_cmd *tmp)
{
	char	*file_name;

	file_name = NULL;
	if (tmp && tmp->next && tmp->next->type == 0)
		file_name = tmp->next->str;
	if (file_name == NULL)
	{
		if (tmp->next && tmp->next->str)
			return (syntax_error(tmp->next->str));
		return (syntax_error("\'new line\'"));
	}
	close(g_mini.fdout);
	if (type == TRUNC)
		g_mini.fdout = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	else
		g_mini.fdout = open(file_name, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
	if (g_mini.fdout == -1)
	{
		no_such_file(file_name);
		return (1);
	}
	dup2(g_mini.fdout, STDOUT);
	g_mini.file = 1;
	return (0);
}

int			redirection_input(t_cmd *tmp)
{
	char	*file_name;

	file_name = NULL;
	if (tmp && tmp->next && tmp->next->type == 0)
		file_name = tmp->next->str;
	if (file_name == NULL)
	{
		if (tmp->next && tmp->next->str)
			return (syntax_error(tmp->next->str));
		return (syntax_error("\'new line\'"));
	}
	close(g_mini.fdin);
	g_mini.fdin = open(file_name, O_RDONLY, S_IRWXU);
	if (g_mini.fdin == -1)
	{
		no_such_file(file_name);
		return (1);
	}
	dup2(g_mini.fdin, STDIN);
	return (0);
}
