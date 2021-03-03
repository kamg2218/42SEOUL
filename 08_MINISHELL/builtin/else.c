/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:19:47 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 15:38:15 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		**make_string(t_cmd *cmd)
{
	int		i;
	int		len;
	char	**str;
	t_cmd	*tmp;

	len = 0;
	tmp = cmd;
	while (tmp && tmp->type == 0)
	{
		len += 1;
		tmp = tmp->next;
	}
	if (!(str = (char **)malloc(sizeof(char *) * (len + 1))))
		return (malloc_error());
	i = -1;
	tmp = cmd;
	while (++i < len)
	{
		str[i] = tmp->str;
		tmp = tmp->next;
	}
	str[i] = NULL;
	return (str);
}

char		*check_command(t_cmd *cmd)
{
	int		len;
	char	*path;
	char	*new;
	t_cmd	*tmp;

	tmp = cmd;
	path = ft_strdup(tmp->str);
	len = ft_strlen(path);
	if ((!(ft_strncmp(&(tmp->str)[len - 3], "cat", 4))
			|| !(ft_strncmp(&(tmp->str)[len - 2], "wc", 3)))
			&& (tmp->next == NULL || tmp->next->type == SEMI
				|| tmp->next->type == PIPE))
		g_mini.sigint = 1;
	while (--len > 0 && path[len] != '/')
		path[len] = 0;
	path[len] = 0;
	new = NULL;
	if (check_directory(path, &(tmp->str)[len + 1]) == 1)
		new = ft_strdup(tmp->str);
	else if (check_directory("/bin", tmp->str) == 1)
		new = ft_strjoin("/bin/", tmp->str);
	else if (check_directory("/usr/bin", tmp->str) == 1)
		new = ft_strjoin("/usr/bin/", tmp->str);
	free(path);
	return (new);
}

int			ft_else(t_cmd *cmd)
{
	pid_t	pid;
	char	**str;
	char	*path;
	int		status;

	if ((str = make_string(cmd)) == NULL)
		return (1);
	g_mini.signal = 0;
	if (!(path = check_command(cmd)))
		return (is_not_command(cmd->str));
	if ((pid = fork()) < 0)
		return (-1);
	if (pid == 0)
		execve(path, str, g_mini.envp);
	else
	{
		wait(&status);
		set_status(status);
	}
	free(path);
	free(str);
	return (0);
}
