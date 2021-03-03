/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:19:26 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/30 17:40:38 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_varclear(t_var **var)
{
	t_var	*tmp;
	t_var	*front;

	tmp = *var;
	if (!tmp)
		return ;
	while (tmp)
	{
		front = tmp;
		tmp = tmp->next;
		if (front->key)
			free(front->key);
		if (front->value)
			free(front->value);
		free(front);
	}
	*var = NULL;
}

t_var		*ft_varnew(int key, int value)
{
	int		i;
	t_var	*var;

	if (!(var = (t_var *)malloc(sizeof(t_var))))
		return (malloc_error());
	if (!(var->key = (char *)malloc(sizeof(char) * key)))
		return (malloc_error());
	i = -1;
	while (++i < key)
		(var->key)[i] = 0;
	if (value > 1)
	{
		if (!(var->value = (char *)malloc(sizeof(char) * value)))
			return (malloc_error());
		i = -1;
		while (++i < value)
			(var->value)[i] = 0;
	}
	else
		var->value = NULL;
	var->next = NULL;
	return (var);
}

void		ft_varadd_back(t_var **var, t_var *new)
{
	t_var	*tmp;

	tmp = *var;
	if (!new)
		return ;
	else if (!tmp)
	{
		*var = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void		check_environ(t_cmd *cmd)
{
	char	*new;
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp && tmp->type != SEMI)
	{
		if (tmp && !(ft_strncmp(tmp->str, "$?", 3)))
			return ;
		new = convert_env(tmp->str, g_mini.env);
		free(tmp->str);
		tmp->str = new;
		convert_bs(tmp);
		tmp = check_del(tmp->bef, tmp);
	}
}

t_cmd		*check_del(t_cmd *pre, t_cmd *tmp)
{
	if (tmp->del == 'Y' && ft_strlen(tmp->str) == 0)
	{
		if (tmp->next)
			tmp->next->bef = pre;
		if (pre)
			pre->next = tmp->next;
		else
			g_mini.cmd = tmp->next;
		free(tmp->str);
		free(tmp);
		if (pre)
			return (pre->next);
		return (g_mini.cmd);
	}
	return (tmp->next);
}
