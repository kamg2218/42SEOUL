/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:19:30 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/30 02:04:13 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		*no_such_file(char *cmd)
{
	ft_putstr_fd(cmd, g_mini.tmpout);
	ft_putstr_fd(": No such file or directory\n", g_mini.tmpout);
	g_mini.signal = 1;
	return (NULL);
}

int			not_enough(char *cmd)
{
	ft_putstr_fd(cmd, g_mini.tmpout);
	ft_putstr_fd(": not enough arguments\n", g_mini.tmpout);
	g_mini.signal = 1;
	return (0);
}

void		bad_assignment(char *cmd)
{
	ft_putstr_fd(cmd, g_mini.tmpout);
	ft_putstr_fd(": bad assignment\n", g_mini.tmpout);
	g_mini.signal = 0;
}

int			is_not_command(char *cmd)
{
	ft_putstr_fd("command not found: ", g_mini.tmpout);
	ft_putstr_fd(cmd, g_mini.tmpout);
	ft_putstr_fd("\n", g_mini.tmpout);
	g_mini.signal = 127;
	return (0);
}

int			no_valid_identifier(char *cmd)
{
	ft_putstr_fd(cmd, g_mini.tmpout);
	ft_putstr_fd(": not a valid identifier\n", g_mini.tmpout);
	g_mini.signal = 1;
	return (0);
}
