/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:20:04 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 16:05:23 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_pwd(t_var *env)
{
	t_var	*tmp;

	tmp = env;
	while (tmp && ft_strncmp(tmp->key, "PWD", 4))
		tmp = tmp->next;
	ft_putstr_fd(tmp->value, 1);
	ft_putstr_fd("\n", 1);
	g_mini.signal = 0;
	return (0);
}

void		get_rid_of_dots(char *value, t_var *tmp, int len)
{
	if (!(ft_strncmp(value, "..", 2)))
	{
		if (ft_strlen(tmp->value) == 1)
			return ;
		len = ft_strlen(tmp->value);
		while (tmp->value[--len] != '/' && len > 1)
			tmp->value[len] = 0;
		tmp->value[len] = 0;
	}
	else if (len <= 2 && value[0] == '.')
		return ;
	else if (value[0] == '/')
	{
		free(tmp->value);
		tmp->value = ft_strdup(value);
	}
	else
		variable_strjoin(value, tmp);
}

void		change_oldpwd(t_var *tmp)
{
	char	*oldpwd;
	t_var	*old;

	old = g_mini.env;
	while (old && ft_strncmp(old->key, "OLDPWD", 7))
		old = old->next;
	if (old == NULL)
		return ;
	if (old->value)
		free(old->value);
	oldpwd = ft_strdup(tmp->value);
	old->value = oldpwd;
}

int			count_slash(char *value)
{
	int		i;

	i = 0;
	while (value[i] && value[i] != '/')
		++i;
	return (i);
}

void		change_pwd(char *value, t_var *tmp)
{
	int		i;
	int		len;
	int		vlen;
	char	*str;

	change_oldpwd(tmp);
	vlen = ft_strlen(value);
	str = ft_strdup(value);
	i = -1;
	while (++i < vlen)
	{
		if (value[i] == '/')
			len = count_slash(&value[i + 1]) + 1;
		else
			len = count_slash(&value[i]);
		ft_strlcpy(str, &value[i], len + 1);
		get_rid_of_dots(str, tmp, len);
		i += len;
	}
	free(str);
}
