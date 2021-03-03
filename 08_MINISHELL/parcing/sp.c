/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:09:02 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/30 02:56:36 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

int		cnt_space(char *str)
{
	int		i;
	char	bef;
	int		res;
	int		quote;

	i = 0;
	res = 0;
	quote = 0;
	while (str[i])
	{
		bef = i > 0 ? str[i - 1] : 0;
		quote = is_quotes(str[i], bef, quote);
		if (quote == 0 && str[i] == ' ' && str[i - 1] != ' ')
			res++;
		i++;
	}
	return (res);
}

void	set_idx(char *str, int **idx, int cnt)
{
	int		i;
	int		j;
	int		quote;
	char	bef;

	i = 0;
	j = 0;
	quote = 0;
	if (!((*idx) = (int *)malloc(sizeof(int) * cnt)))
		malloc_error();
	while (str[i])
	{
		bef = i > 0 ? str[i - 1] : 0;
		quote = is_quotes(str[i], bef, quote);
		if (quote == 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			(*idx)[j] = i;
			j++;
		}
		i++;
	}
}

void	new_cmd(t_cmd **res, char *temp)
{
	if (*res == NULL)
		*res = ft_lst_start(temp, 0);
	else
		ft_lstadd(*res, temp, 0);
	return ;
}

t_cmd	*process_split(t_cmd *tar, int cnt)
{
	t_cmd	*res;
	int		*idx;
	int		bef;
	int		i;
	char	*temp;

	res = NULL;
	i = 0;
	bef = 0;
	if (cnt == 0)
		return (ft_lst_start(ft_strtrim(tar->str, " "), tar->type));
	set_idx(tar->str, &idx, cnt);
	while (i < cnt)
	{
		temp = ldup_trim(tar->str, bef, idx[i] - 1);
		new_cmd(&res, temp);
		bef = idx[i++] + 1;
	}
	free(idx);
	temp = ldup_trim(tar->str, bef, ft_strlen(tar->str) - 1);
	new_cmd(&res, temp);
	return (res);
}

t_cmd	*split_space(t_cmd *start)
{
	int		cnt;
	t_cmd	*res;
	t_cmd	*pos;

	res = NULL;
	pos = start;
	while (pos)
	{
		cnt = cnt_space(pos->str);
		if (res == NULL)
			res = process_split(pos, cnt);
		else
			ft_lstmerge(res, process_split(pos, cnt));
		pos = pos->next;
	}
	return (res);
}
