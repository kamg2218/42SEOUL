/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_dict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:31:24 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/09 23:36:49 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_total.h"

int		ft_validate_key(char *str)
{
	int		i;
	int		count;
	int		colon_index;

	i = -1;
	count = 0;
	colon_index = 0;
	while (*(str + ++i) != '\n')
	{
		if (!ft_is_numeric(*(str)))
			return (0);
		if (ft_is_numeric(*(str + i)))
		{
			count++;
			i++;
		}
		if (ft_is_space(str + i))
			i++;
		if (*(str + i) == ':')
			colon_index = i;
	}
	if (colon_index == 0)
		return (0);
	else
		return (colon_index);
}

int		ft_validate_value(char *str)
{
	int	i;
	int	colon_index;

	colon_index = ft_validate_key(str);
	if (colon_index == 0)
		return (0);
	i = colon_index + 1;
	while (*(str + i) != '\n')
	{
		if (ft_is_non_printable(str + i))
			return (0);
		else
			i++;
	}
	return (1);
}

int		ft_validate_dict(char *str)
{
	if (!ft_validate_key(str))
		return (0);
	if (!ft_validate_value(str))
		return (0);
	return (1);
}
