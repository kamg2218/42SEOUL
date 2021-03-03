/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 22:51:02 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/31 00:15:12 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void	treat_string(t_quote *q_val, char **result)
{
	char	*src;
	char	*temp;

	q_val->i = (q_val->str)[q_val->i] == '\\' ? q_val->i + 1 : q_val->i;
	src = ft_strldup(q_val->str, q_val->index, q_val->i);
	check_dollar(src);
	for_env_dist(&src);
	temp = *result;
	if (!(*result = ft_strjoin(*result, src)))
		malloc_error();
	free(temp);
	free(src);
	check_bs(result, 0);
	q_val->i = set_i(q_val->i, (q_val->str)[q_val->i], q_val->quote);
	q_val->index = q_val->i;
	return ;
}

void	treat_single(t_quote *q_val, char **result)
{
	char	*src;
	char	*temp;

	src = ft_strldup(q_val->str, q_val->index, q_val->i);
	temp = src;
	src = trim_quote(src);
	for_env_dist(&src);
	free(temp);
	temp = *result;
	if (!(*result = ft_strjoin(*result, src)))
		malloc_error();
	free(temp);
	free(src);
	q_val->i = set_i(q_val->i, (q_val->str)[q_val->i], q_val->quote);
	q_val->index = q_val->i;
	return ;
}

void	treat_double(t_quote *q_val, char **result)
{
	char	*src;
	char	*temp;

	src = ft_strldup(q_val->str, q_val->index, q_val->i);
	temp = src;
	src = trim_quote(src);
	for_env_dist(&src);
	free(temp);
	check_dollar(src);
	temp = *result;
	if (!(*result = ft_strjoin(*result, src)))
		malloc_error();
	free(temp);
	free(src);
	check_bs(result, 2);
	q_val->i = set_i(q_val->i, (q_val->str)[q_val->i], q_val->quote);
	q_val->index = q_val->i;
	return ;
}

void	check_dollar(char *str)
{
	char	*pos;

	if (!ft_strcmp(str, "$"))
		return ;
	pos = pos_env(str);
	while (pos)
	{
		*pos = (char)(-DOLLAR);
		pos = pos_env(pos);
	}
	return ;
}

void	for_env_dist(char **result)
{
	char	c;

	c = (*result)[0];
	if (ft_isalnum(c) || c == '_')
		(*result)[0] = (char)(-c);
	return ;
}
