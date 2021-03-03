/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:19:36 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 00:01:17 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		export_long(t_cmd *cmd, t_var *env)
{
	int		equal;
	int		len;
	int		lon;
	t_var	*new;
	t_cmd	*tmp;

	tmp = cmd;
	len = 0;
	equal = get_export_len(&len, tmp);
	if (equal < -1 || equal == 0)
		return ((void)no_valid_identifier(tmp->str));
	lon = -1;
	if (equal > 0)
	{
		lon = len - equal - 1;
		len = equal;
	}
	new = ft_varnew(len + 1, lon + 1);
	ft_strlcpy(new->key, tmp->str, len + 1);
	if (lon >= 1)
		ft_strlcpy(new->value, &(tmp->str)[equal + 1], lon + 1);
	export_env(env, new, ft_strlen(new->key));
}

int			export_single(t_var *env)
{
	t_var	*tmp;
	t_node	*head;

	head = NULL;
	tmp = env;
	while (tmp->next)
	{
		insert(&head, create(tmp->key, tmp->value));
		tmp = tmp->next;
	}
	traverse(head);
	destroy(&head);
	g_mini.signal = 0;
	return (0);
}

int			ft_export(t_cmd *cmd, t_var *env)
{
	t_cmd	*tmp;

	tmp = cmd;
	if (tmp && (tmp->next == NULL || tmp->next->type != 0))
		return (export_single(env));
	tmp = tmp->next;
	while (tmp && tmp->type == 0)
	{
		export_long(tmp, env);
		tmp = tmp->next;
	}
	return (0);
}
