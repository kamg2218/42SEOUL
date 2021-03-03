/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:18:58 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 15:15:30 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*cd_wave(t_var *env)
{
	t_var	*home;

	home = env;
	while (home && ft_strncmp(home->key, "HOME", 5))
		home = home->next;
	if (home)
		return (ft_strdup(home->value));
	return (NULL);
}

void		variable_strjoin(char *value, t_var *tmp)
{
	int		len;
	char	*new;

	len = ft_strlen(tmp->value);
	if ((tmp->value)[len - 1] != '/')
		new = ft_strjoin(tmp->value, "/");
	else
		new = ft_strdup(tmp->value);
	free(tmp->value);
	tmp->value = ft_strjoin(new, value);
	free(new);
}

int			is_pipe_in_cmd(void)
{
	t_cmd	*tmp;

	tmp = g_mini.cmd;
	while (tmp && tmp->type != SEMI)
	{
		if (tmp->type == PIPE)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_cd(t_cmd *cmd, t_var *env)
{
	char	*value;
	t_var	*tmp;

	if (is_pipe_in_cmd())
		return (0);
	tmp = env;
	while (tmp && ft_strncmp(tmp->key, "PWD", 4))
		tmp = tmp->next;
	if (cmd->next == NULL || cmd->next->str == NULL || cmd->next->type == SEMI
			|| !(ft_strncmp(cmd->next->str, "~", 2)))
		value = cd_wave(env);
	else
		value = ft_strdup(cmd->next->str);
	if (!(chdir(value)))
	{
		g_mini.signal = 0;
		change_pwd(value, tmp);
	}
	else
		no_such_file(cmd->str);
	free(value);
	return (0);
}
