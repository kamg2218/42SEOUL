/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:20:16 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/30 04:42:46 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		connect_var(t_var *pre, t_var *tmp)
{
	pre->next = tmp->next;
	free(tmp->key);
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}

void		unset_var(t_cmd *cmd, t_var *env, int len)
{
	t_var	*pre;
	t_var	*tmp;

	if (is_pipe_in_cmd())
		return ;
	tmp = env;
	pre = NULL;
	while (tmp)
	{
		if (!(ft_strncmp(tmp->key, cmd->str, ft_strlen(tmp->key) + 1))
				&& ft_strlen(tmp->key) == (size_t)len)
			return (connect_var(pre, tmp));
		pre = tmp;
		tmp = tmp->next;
	}
}

int			ft_unset(t_cmd *cmd, t_var *env)
{
	int		len;
	t_cmd	*tmp;

	g_mini.signal = 0;
	tmp = cmd;
	while (tmp && tmp->next && tmp->next->type != 0)
		return (0);
	tmp = tmp->next;
	while (tmp)
	{
		len = 0;
		while ((tmp->str)[len])
		{
			if ((tmp->str)[len] == '=')
				return (no_valid_identifier("unset"));
			++len;
		}
		unset_var(tmp, env, len);
		tmp = tmp->next;
	}
	return (0);
}
