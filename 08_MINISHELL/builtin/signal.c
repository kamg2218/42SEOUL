/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:20:11 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 16:43:10 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		handle_sigint(int sig)
{
	(void)sig;
	write(1, " \b\b \b\b", 6);
	if (g_mini.sigint == 0 && g_mini.parent == 1)
	{
		write(g_mini.tmpout, "\n", 1);
		drawing_side();
		g_mini.signal = 1;
	}
	else if (g_mini.sigint)
		g_mini.signal = 130;
	else
		g_mini.signal = 1;
}

void		handle_sigquit(int sig)
{
	write(1, " \b\b \b\b", 6);
	kill(sig, SIGQUIT);
	(void)sig;
	g_mini.signal = 0;
}
