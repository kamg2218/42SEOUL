/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:19:36 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/30 23:59:58 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		print_export(t_node *tmp)
{
	if (tmp->print == 1)
		return ;
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(tmp->key, 1);
	if (tmp->value)
	{
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(tmp->value, 1);
		ft_putstr_fd("\"", 1);
	}
	write(1, "\n", 1);
	tmp->print = 1;
}

void		export_env(t_var *env, t_var *new, int k_len)
{
	int		len;
	t_var	*tmp;
	t_var	*pre;

	tmp = env;
	pre = NULL;
	while (tmp->next)
	{
		len = ft_strlen(tmp->key);
		if (k_len == len && !(ft_strncmp(tmp->key, new->key, len)))
		{
			if (tmp->value)
				free(tmp->value);
			tmp->value = new->value;
			free(new->key);
			free(new);
			g_mini.signal = 0;
			return ;
		}
		pre = tmp;
		tmp = tmp->next;
	}
	pre->next = new;
	new->next = tmp;
	g_mini.signal = 0;
}

int			get_export_len(int *len, t_cmd *tmp)
{
	int		i;
	int		equal;

	i = -1;
	equal = -1;
	while ((tmp->str)[++i])
	{
		if ((tmp->str)[i] == '=')
		{
			if (equal != -1)
				return (-2);
			equal = i;
		}
	}
	*len = i;
	return (equal);
}
