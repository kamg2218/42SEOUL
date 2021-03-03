/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:09:02 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/30 01:36:47 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void	initzero(int *i, int *j, int *quote)
{
	*i = 0;
	*j = 0;
	*quote = 0;
	return ;
}

void	malloc_info(t_operator *op_info)
{
	int count;

	count = op_info->cnt;
	if (!(op_info->type = (int *)malloc(sizeof(int) * count)))
		malloc_error();
	if (!(op_info->index = (int *)malloc(sizeof(int) * count)))
		malloc_error();
	return ;
}

char	*ldup_trim(char *str, int start, int end)
{
	char	*src;
	char	*result;

	src = ft_strldup(str, start, end);
	if (src == NULL)
		return (malloc_error());
	if (!(result = ft_strtrim(src, " ")))
		return (malloc_error());
	free(src);
	return (result);
}

int		is_opcha(char cur)
{
	if (cur == '<' | cur == '>')
		return (1);
	else if (cur == '|' | cur == ';')
		return (2);
	return (0);
}

void	free_struct(t_operator tar)
{
	if (tar.type)
		free(tar.type);
	if (tar.index)
		free(tar.index);
	return ;
}
