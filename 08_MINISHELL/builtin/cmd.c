/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:20:25 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 14:50:37 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					preprocess_command(t_cmd *start)
{
	size_t			i;
	size_t			len;

	if (start == NULL || start->str == NULL
			|| !(ft_strncmp(start->str, "", 1)))
		return (2);
	else if (start && start->str && !(ft_strncmp(start->str, "exit", 5)))
		return (1);
	else
	{
		i = 0;
		len = ft_strlen(start->str);
		while (i < len && (start->str)[i] != '/')
			++i;
		if (i >= len)
			return (0);
		if (relative_path(start->str, start->str) == 1)
			return (0);
		no_such_file(start->str);
		return (2);
	}
}

int					is_command(t_cmd *start)
{
	int				re;

	if ((re = preprocess_command(start)) > 0)
		return (re);
	else if (check_strncmp(start->str, "pwd")
			|| !(ft_strncmp(start->str, "pwd", 4)))
		return (ft_pwd(g_mini.env));
	else if (check_strncmp(start->str, "cd")
			|| !(ft_strncmp(start->str, "cd", 3)))
		return (ft_cd(start, g_mini.env));
	else if (check_strncmp(start->str, "echo")
			|| !(ft_strncmp(start->str, "echo", 5)))
		return (ft_echo(start));
	else if (check_strncmp(start->str, "env"))
		return (ft_env(start, g_mini.env));
	else if (!(ft_strncmp(start->str, "export", 7)))
		return (ft_export(start, g_mini.env));
	else if (!(ft_strncmp(start->str, "unset", 6)))
		return (ft_unset(start, g_mini.env));
	else if (check_strncmp(start->str, start->str))
		return (ft_else(start));
	return (is_not_command(start->str));
}

char				*get_path(t_var *lst, int start, int len)
{
	char			*path;

	if (!(path = (char *)malloc(sizeof(char) * len)))
		return ((char *)malloc_error);
	ft_strlcpy(path, &(lst->value)[start], len);
	return (path);
}

int					check_strncmp(char *cmd, char *str)
{
	int				re;
	t_var			*lst;
	char			*new;

	re = 0;
	new = NULL;
	if (absolute_path(cmd, str))
		re = 1;
	else if (relative_path(cmd, str))
		re = 1;
	else if (relative_path((new = ft_strjoin("./", cmd)), str))
		re = 1;
	else
	{
		lst = g_mini.env;
		while (lst && ft_strncmp(lst->key, "PATH", 5))
			lst = lst->next;
		if (lst && environment_path(lst, cmd, str))
			re = 1;
	}
	if (new)
		free(new);
	return (re);
}

void				get_command(void)
{
	char			*buf;
	t_list			**start;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	drawing_side();
	buf = NULL;
	start = get_buffer();
	if (get_next_line(0, &buf, start) == -1)
		return ;
	ft_lstclear(start);
	g_mini.cmd = tokenize(buf);
	free(buf);
}
