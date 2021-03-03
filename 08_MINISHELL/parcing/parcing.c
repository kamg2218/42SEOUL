/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:09:02 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/30 16:38:17 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

t_cmd	*split_op(char *str, t_operator op_info)
{
	int		i;
	int		bef;
	t_cmd	*res;
	char	*temp;

	i = -1;
	res = NULL;
	while (++i < op_info.cnt)
	{
		bef = (i == 0) ? 0 : dist_optype(op_info, i);
		temp = ldup_trim(str, bef, (op_info.index)[i] - 1);
		if (res == NULL)
			res = ft_lst_start(temp, 0);
		else
			ft_lstadd(res, temp, 0);
		temp = convert_op(op_info, i);
		ft_lstadd(res, temp, (op_info.type)[i]);
	}
	bef = (i == 0) ? 0 : dist_optype(op_info, i);
	temp = ldup_trim(str, bef, ft_strlen(str) - 1);
	if (res == NULL)
		res = ft_lst_start(temp, 0);
	else
		ft_lstadd(res, temp, 0);
	return (res);
}

int		only_env(char *str)
{
	int		i;

	i = 0;
	if (str[i++] != (char)(-DOLLAR))
		return (0);
	while (str[i])
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

void	handle_quote_env(t_cmd **start)
{
	int		i;
	char	*temp;
	t_quote	q_val;
	t_cmd	*pos;

	i = 0;
	pos = *start;
	while (pos)
	{
		temp = handle_quotes(pos->str, &q_val);
		free(pos->str);
		pos->str = temp;
		pos->del = 'N';
		if (q_val.exp == 0 && only_env(temp))
			pos->del = 'Y';
		pos = pos->next;
	}
	return ;
}

char	*handle_quotes(char *str, t_quote *q_val)
{
	char	*result;

	result = init_handle_quotes(q_val, str);
	while (str[q_val->i])
	{
		if ((q_val->res = wh_quotedstr(*q_val)) != -1)
		{
			q_val->exp += q_val->res;
			if (q_val->res == 0)
				treat_string(q_val, &result);
			else if (q_val->res == 1)
				treat_single(q_val, &result);
			else if (q_val->res == 2)
				treat_double(q_val, &result);
			if (!next_step(q_val))
				break ;
		}
		else
			q_val->i = set_i(q_val->i, str[q_val->i], q_val->quote);
	}
	return (result);
}

t_cmd	*tokenize(char *input)
{
	t_cmd		*temp;
	t_cmd		*cmd;
	t_operator	op_info;

	if (quote_error(input))
		return (NULL);
	if (input[0] == '\0')
		return (ft_lst_start(ft_strdup(""), 0));
	find_operator(input, &op_info);
	temp = split_op(input, op_info);
	free_struct(op_info);
	cmd = split_space(temp);
	free_cmd(temp);
	handle_quote_env(&cmd);
	re_arrange(&cmd);
	return (cmd);
}
