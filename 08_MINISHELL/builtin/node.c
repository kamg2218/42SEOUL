/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:19:41 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/22 01:15:07 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			traverse(t_node *head)
{
	t_node		*tmp;

	tmp = head;
	while (tmp)
	{
		while (tmp->left_next && !(tmp->left_next->print))
			tmp = tmp->left_next;
		if (tmp->print && tmp->right_next && !tmp->right_next->print)
			tmp = tmp->right_next;
		print_export(tmp);
		if (tmp->prev == NULL
				&& ((tmp->right_next && tmp->right_next->print)
					|| !(tmp->right_next)))
			return ;
		if (tmp->prev && tmp->right_next == NULL)
			tmp = tmp->prev;
		else if (tmp->right_next && !tmp->right_next->print)
			tmp = tmp->right_next;
		if (tmp->print)
		{
			while (tmp->prev && tmp->print)
				tmp = tmp->prev;
		}
	}
}

t_node			*create(char *key, char *value)
{
	t_node		*new;

	if (!(new = (t_node *)malloc(sizeof(t_node) * 1)))
		return (malloc_error());
	new->key = key;
	new->value = value;
	new->left_next = NULL;
	new->right_next = NULL;
	new->prev = NULL;
	new->print = 0;
	return (new);
}

void			destroy(t_node **head)
{
	t_node		*pre;
	t_node		*tmp;

	tmp = *head;
	while (tmp)
	{
		while (tmp->left_next)
			tmp = tmp->left_next;
		while (tmp->right_next)
			tmp = tmp->right_next;
		if (tmp->left_next)
			continue ;
		pre = tmp->prev;
		if (pre && pre->right_next == tmp)
			pre->right_next = NULL;
		else if (pre && pre->left_next == tmp)
			pre->left_next = NULL;
		free(tmp);
		tmp = pre;
	}
	*head = NULL;
}

t_node			*move_tmp(t_node *tmp, t_node *new)
{
	int			len;
	int			lon;

	if (tmp == NULL)
		return (NULL);
	len = ft_strlen(new->key);
	while (tmp)
	{
		lon = ft_strlen(tmp->key);
		lon = len > lon ? len : lon;
		if (ft_strncmp(new->key, tmp->key, lon) > 0)
		{
			if (tmp->right_next == NULL)
				return (tmp);
			tmp = tmp->right_next;
		}
		else
		{
			if (tmp->left_next == NULL)
				return (tmp);
			tmp = tmp->left_next;
		}
	}
	return (tmp);
}

void			insert(t_node **head, t_node *new)
{
	int			len;
	int			lon;
	t_node		*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		*head = new;
		return ;
	}
	tmp = move_tmp(tmp, new);
	len = ft_strlen(new->key);
	lon = ft_strlen(tmp->key);
	lon = len > lon ? len : lon;
	if (ft_strncmp(new->key, tmp->key, lon) > 0)
		tmp->right_next = new;
	else
		tmp->left_next = new;
	new->prev = tmp;
}
