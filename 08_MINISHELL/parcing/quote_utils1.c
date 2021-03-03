/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 22:51:02 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/30 00:28:23 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

int		is_quotes(char c, char bef, int quote)
{
	if (c == '"' || c == '\'')
	{
		if (c == '"' && bef == '\\')
			return (quote);
		if (quote == 0 && bef != '\\')
		{
			if (c == '"')
				return (2);
			else if (c == '\'')
				return (1);
		}
		else if (quote == 1 && c == '\'')
			return (0);
		else if (quote == 2 && c == '"' && bef != '\\')
			return (0);
	}
	return (quote);
}

int		wh_quotetype(char bef, char c)
{
	if ((bef != '\\' || bef == '\0') && c == '\'')
		return (1);
	else if ((bef != '\\' || bef == '\0') && c == '"')
		return (2);
	return (0);
}

int		set_i(int i, char cur, int quote)
{
	if (quote != 1 && cur == '\\')
		return (i + 2);
	return (i + 1);
}

int		no_quote(t_quote q_val)
{
	int		len;
	char	cur;
	char	next;
	char	n_next;

	len = (int)ft_strlen(q_val.str);
	cur = (q_val.str)[q_val.i];
	next = q_val.i >= len - 1 ? '\0' : (q_val.str)[q_val.i + 1];
	n_next = q_val.i >= len - 2 ? '\0' : (q_val.str)[q_val.i + 2];
	if (q_val.quote == 0)
	{
		if (q_val.quote != wh_quotetype(cur, next))
			return (1);
		else if (q_val.i == len - 1)
			return (1);
		else if (q_val.i == len - 2 && cur == '\\')
			return (1);
		else if (cur == '\\' && q_val.i < len - 2
					&& wh_quotetype('\0', n_next) != 0)
			return (1);
	}
	return (0);
}
