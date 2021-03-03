/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:18:19 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 00:07:58 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd		*find_position(t_cmd *cmd, int *opt)
{
	t_cmd	*tmp;

	*opt = 0;
	tmp = cmd->next;
	while (tmp && tmp->type != SEMI && tmp->type != PIPE
			&& !(ft_strncmp(tmp->str, "-n", 3)))
	{
		*opt = 1;
		tmp = tmp->next;
	}
	return (tmp);
}

t_cmd		*put_string(t_cmd *cmd)
{
	char	*str;
	t_cmd	*tmp;

	tmp = cmd;
	str = NULL;
	if (tmp && !(ft_strncmp(tmp->str, "$?", 3)))
	{
		str = ft_itoa(g_mini.signal);
		ft_putstr_fd(str, STDOUT);
		free(str);
	}
	else if (tmp && tmp->type == 0)
		ft_putstr_fd(tmp->str, STDOUT);
	if (tmp)
		tmp = tmp->next;
	if (tmp && tmp->type == 0)
		ft_putstr_fd(" ", STDOUT);
	return (tmp);
}

int			ft_echo(t_cmd *cmd)
{
	int		opt;
	t_cmd	*tmp;

	tmp = find_position(cmd, &opt);
	while (tmp && tmp->type == 0)
	{
		if (tmp->type != 0)
		{
			tmp = tmp->next;
			if (tmp)
				tmp = tmp->next;
			continue ;
		}
		tmp = put_string(tmp);
	}
	if (opt != 1)
		ft_putstr_fd("\n", STDOUT);
	g_mini.signal = 0;
	return (0);
}
