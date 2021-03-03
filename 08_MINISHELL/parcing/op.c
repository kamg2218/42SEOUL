/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:09:02 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/31 15:58:33 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

int		cnt_operator(char *str)
{
	int		i;
	int		cnt;
	int		len;
	int		quote;
	char	bef;

	initzero(&i, &cnt, &quote);
	bef = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (!(quote = is_quotes(str[i], bef, quote))
			&& is_opcha(str[i]) && (i == 0 || bef != '\\'))
		{
			cnt++;
			if (i != len - 1 && (is_opcha(str[i + 1]) == 1))
				i++;
		}
		bef = str[i] == '\\' && bef == '\\' ? '\0' : str[i];
		i++;
	}
	return (cnt);
}

int		dist_operator(char *str, int i)
{
	if (str[i] == '|')
		return (PIPE);
	else if (str[i] == '>')
	{
		if (str[i + 1] == '>')
			return (GREATGREAT);
		return (GREAT);
	}
	else if (str[i] == '<')
		return (LESS);
	else if (str[i] == ';')
		return (SEMI);
	return (0);
}

int		dist_optype(t_operator op_info, int i)
{
	int	val;

	val = (op_info.index)[i - 1];
	if (op_info.type[i - 1] != GREATGREAT)
		val += 1;
	else
		val += 2;
	return (val);
}

char	*convert_op(t_operator op_info, int i)
{
	char	*result;

	result = NULL;
	if (op_info.type[i] == PIPE)
		result = ft_strdup("|");
	else if (op_info.type[i] == GREAT)
		result = ft_strdup(">");
	else if (op_info.type[i] == LESS)
		result = ft_strdup("<");
	else if (op_info.type[i] == GREATGREAT)
		result = ft_strdup(">>");
	else if (op_info.type[i] == SEMI)
		result = ft_strdup(";");
	if (!result)
		return (malloc_error());
	return (result);
}

void	find_operator(char *str, t_operator *op_info)
{
	int		i;
	int		j;
	int		len;
	int		quote;
	char	bef;

	bef = 0;
	initzero(&i, &j, &quote);
	len = ft_strlen(str);
	op_info->cnt = cnt_operator(str);
	malloc_info(op_info);
	while (str[i])
	{
		if (!(quote = is_quotes(str[i], bef, quote))
			&& is_opcha(str[i]) && (i == 0 || bef != '\\'))
		{
			(op_info->index)[j] = i;
			(op_info->type)[j] = dist_operator(str, i);
			if ((op_info->type)[j] == GREATGREAT)
				i++;
			j++;
		}
		bef = str[i] == '\\' && bef == '\\' ? '\0' : str[i];
		i++;
	}
}
