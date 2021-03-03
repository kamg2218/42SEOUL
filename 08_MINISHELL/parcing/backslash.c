/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 11:36:43 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/31 03:57:31 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

char	*process_bs(char *str, int option, int len)
{
	int		i;
	char	*result;

	i = 0;
	if (!(result = ft_strdup("")))
		return (malloc_error());
	while (str[i])
	{
		if (str[i] == '\\' && i < len - 1 &&
			(option == 0 || str[i + 1] == '\\' || str[i + 1] == '"'))
		{
			charadd(&result, (char)(-str[i + 1]));
			i++;
		}
		else if (str[i] == '\\' && i == len - 1
				&& (i == 0 || str[i = 1] != '\\'))
			charadd(&result, ' ');
		else
			charadd(&result, str[i]);
		i++;
	}
	return (result);
}

void	check_bs(char **str, int option)
{
	char	*temp;
	int		len;

	temp = *str;
	len = (int)ft_strlen(temp);
	*str = process_bs(temp, option, len);
	free(temp);
	return ;
}

void	convert_bs(t_cmd *pos)
{
	int i;

	i = 0;
	while ((pos->str)[i])
	{
		if ((pos->str)[i] < 0)
			(pos->str)[i] *= (-1);
		i++;
	}
	return ;
}
