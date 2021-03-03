/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 00:28:36 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 03:38:27 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		close_pipe(int **fdpipe, int count)
{
	int		i;

	i = -1;
	while (++i < count)
	{
		close(fdpipe[i][0]);
		close(fdpipe[i][1]);
	}
}

int			**get_fdpipe(t_pipe *pip)
{
	int		i;
	int		**fdpipe;
	t_cmd	*tmp;

	i = -1;
	pip->count = 0;
	tmp = g_mini.cmd;
	while (++i < pip->len && tmp)
	{
		if (tmp->type == PIPE)
			++pip->count;
		tmp = tmp->next;
	}
	if (!(fdpipe = (int **)malloc(sizeof(int *) * (pip->count + 1))))
		return ((int **)malloc_error());
	i = -1;
	while (++i < pip->count)
	{
		if (!(fdpipe[i] = (int *)malloc(sizeof(int) * 2)))
			return ((int **)malloc_error());
		pipe(fdpipe[i]);
	}
	fdpipe[i] = NULL;
	return (fdpipe);
}

void		arrange_inout(int i, t_pipe *pipe)
{
	if (i != 0 && is_last_cmd(pipe->start) == 0)
		dup2((pipe->fdpipe)[i][1], STDOUT);
	else if (i == 0 && g_mini.file == 0)
		dup2((pipe->fdpipe)[i][1], STDOUT);
	else if (i != 0)
		dup2(g_mini.tmpout, STDOUT);
	if (i != 0)
		dup2((pipe->fdpipe)[i - 1][0], STDIN);
}

void		pipe_process(int i, t_pipe *pipe)
{
	pid_t	pid;
	t_cmd	*tmp;

	if ((pid = fork()) < 0)
		perror("fork");
	else if (pid == 0)
	{
		g_mini.parent = 0;
		arrange_inout(i, pipe);
		close_pipe(pipe->fdpipe, pipe->count);
		command_line(pipe->start);
		exit(0);
	}
	tmp = pipe->start;
	while (tmp && tmp->type != PIPE && tmp->type != SEMI)
		tmp = tmp->next;
	if (tmp)
		pipe->start = tmp->next;
	else
		pipe->start = NULL;
}

void		piping(int len)
{
	int		i;
	int		status;
	t_pipe	pipe;

	pipe.len = len;
	if (!(pipe.fdpipe = get_fdpipe(&pipe)))
		return ;
	i = -1;
	pipe.start = g_mini.cmd;
	while (++i <= pipe.count)
		pipe_process(i, &pipe);
	close_pipe(pipe.fdpipe, pipe.count);
	if (g_mini.parent == 1)
	{
		i = -1;
		while (++i <= pipe.count)
		{
			wait(&status);
			set_status(status);
		}
	}
	i = -1;
	while (++i < pipe.count)
		free(pipe.fdpipe[i]);
	free(pipe.fdpipe);
}
