/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:19:21 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/30 03:01:27 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_var		*make_env(char **envp)
{
	int		i;
	int		len;
	int		k_len;
	t_var	*tmp;
	t_var	*new;

	tmp = NULL;
	i = -1;
	while (envp[++i])
	{
		len = ft_strlen(envp[i]);
		k_len = 0;
		while (envp[i][k_len] && envp[i][k_len] != '=')
			++k_len;
		len -= k_len;
		if (envp[i][k_len] == '=')
			len -= 1;
		new = ft_varnew(k_len + 1, len + 1);
		ft_strlcpy(new->key, envp[i], k_len + 1);
		if (len > 0)
			ft_strlcpy(new->value, &envp[i][k_len + 1], len + 1);
		ft_varadd_back(&tmp, new);
	}
	return (tmp);
}

int			ft_env(t_cmd *cmd, t_var *t_env)
{
	t_var	*tmp;
	t_cmd	*new;

	new = cmd;
	if (new->next && new->next->type != SEMI && new->next->type != PIPE
			&& new->next->type != GREAT && new->next->type != LESS
			&& new->next->type != GREATGREAT)
		return (0);
	tmp = t_env;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(tmp->value, 1);
			write(1, "\n", 1);
		}
		tmp = tmp->next;
	}
	g_mini.signal = 0;
	return (0);
}
