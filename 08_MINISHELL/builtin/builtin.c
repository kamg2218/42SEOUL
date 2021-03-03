/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 00:28:36 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/30 04:43:03 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			is_builtin(char *str)
{
	if (!(ft_strncmp(str, "unset", 6)))
		return (1);
	else if (!(ft_strncmp(str, "export", 7)))
		return (1);
	else if (!(ft_strncmp(str, "env", 4)))
		return (1);
	else if (!(ft_strncmp(str, "echo", 5)))
		return (1);
	else if (!(ft_strncmp(str, "cd", 3)))
		return (1);
	else if (!(ft_strncmp(str, "pwd", 4)))
		return (1);
	return (0);
}
