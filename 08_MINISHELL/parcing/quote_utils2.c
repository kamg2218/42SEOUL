/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 22:51:02 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/30 13:04:47 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

int		wh_quotedstr(t_quote q_val)
{
	int		len;
	char	bef;
	char	cur;
	char	next;

	len = (int)ft_strlen(q_val.str);
	cur = (q_val.str)[q_val.i];
	bef = q_val.i < 1 ? '\0' : (q_val.str)[q_val.i - 1];
	next = q_val.i >= len - 1 ? '\0' : (q_val.str)[q_val.i + 1];
	if (q_val.str == NULL)
		return (-1);
	if (no_quote(q_val))
		return (0);
	else if (q_val.index != q_val.i &&
				q_val.quote == 1 &&
				(q_val.quote == wh_quotetype('\0', cur)))
		return (1);
	else if (q_val.index != q_val.i &&
				q_val.quote == 2 &&
				(q_val.quote == wh_quotetype('\0', cur)))
		return (2);
	return (-1);
}

char	*init_handle_quotes(t_quote *q_val, char *str)
{
	char	*result;
	int		len;

	len = (int)ft_strlen(str);
	q_val->i = 0;
	q_val->index = 0;
	q_val->quote = wh_quotetype('\0', str[0]);
	q_val->str = str;
	q_val->exp = 0;
	if (q_val->i >= len)
		result = ft_strdup(str);
	else
		result = ft_strdup("");
	if (!result)
		malloc_error();
	return (result);
}

char	*trim_quote(char *str)
{
	char	*result;
	int		i;
	int		cnt;

	i = 0;
	cnt = ft_strlen(str) - 2;
	result = (char *)malloc(sizeof(char) * (cnt + 1));
	if (result == NULL)
		return (malloc_error());
	while (i < cnt)
	{
		result[i] = str[i + 1];
		i++;
	}
	result[cnt] = '\0';
	return (result);
}

int		next_step(t_quote *q_val)
{
	int		len;
	char	bef;
	char	cur;

	len = ft_strlen(q_val->str);
	bef = (q_val->str)[q_val->i - 1];
	cur = (q_val->str)[q_val->i];
	if (q_val->i >= len)
		return (0);
	q_val->quote = wh_quotetype(bef, cur);
	return (1);
}
