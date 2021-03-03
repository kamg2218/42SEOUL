/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:19:47 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 03:25:38 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					environment_path(t_var *lst, char *cmd, char *str)
{
	int				len;
	int				start;
	char			*path;

	if (ft_strncmp(str, cmd, ft_strlen(str) + 1))
		return (0);
	len = -1;
	start = 0;
	while ((lst->value)[++len])
	{
		if ((lst->value)[len] == ':')
		{
			if (!(path = get_path(lst, start, len - start + 1)))
				return (-1);
			if (check_directory(path, cmd))
			{
				free(path);
				return (1);
			}
			free(path);
			start = len + 1;
		}
	}
	return (0);
}

int					relative_path(char *cmd, char *str)
{
	int				len;
	char			*path;

	len = ft_strlen(cmd);
	path = ft_strdup(cmd);
	while (--len >= 0 && path[len] != '/')
		path[len] = 0;
	if (len < 0)
	{
		free(path);
		return (0);
	}
	path[len] = 0;
	if (len > 0 && check_directory(path, &cmd[len + 1])
			&& (!(ft_strncmp(str, &cmd[len + 1], ft_strlen(str) + 1))
				|| !(ft_strncmp(str, cmd, ft_strlen(str) + 1))))
	{
		free(path);
		return (1);
	}
	free(path);
	return (0);
}

int					absolute_path(char *cmd, char *str)
{
	int				re;
	int				len;
	char			*path;

	if (cmd[0] != '/')
		return (0);
	path = ft_strdup(cmd);
	len = ft_strlen(path);
	if (len != 1 && path[len - 1] == '/')
		path[len - 1] = 0;
	while (--len >= 0 && path[len] != '/')
		path[len] = 0;
	if (len < 0)
	{
		free(path);
		return (0);
	}
	path[len] = 0;
	re = 0;
	if (check_directory(path, &cmd[len + 1]))
		re = change_cmd(cmd, str, len);
	free(path);
	return (re);
}

int					change_cmd(char *cmd, char *str, int len)
{
	char			*new;

	new = ft_strdup(cmd);
	ft_strlcpy(new, &new[len + 1], ft_strlen(new) - len);
	if (!(ft_strncmp(new, str, ft_strlen(new)))
			|| !(ft_strncmp(cmd, str, ft_strlen(cmd))))
	{
		free(new);
		return (1);
	}
	free(new);
	return (0);
}

int					check_directory(char *path, char *cmd)
{
	DIR				*dp;
	struct dirent	*rd;

	if ((dp = opendir(path)) == NULL)
		return (0);
	while ((rd = readdir(dp)) != NULL)
	{
		if (!(ft_strncmp(rd->d_name, cmd, ft_strlen(rd->d_name)))
				&& ft_strlen(rd->d_name) == ft_strlen(cmd))
		{
			closedir(dp);
			return (1);
		}
	}
	closedir(dp);
	return (0);
}
