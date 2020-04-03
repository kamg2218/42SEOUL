/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:30:22 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/09 23:36:58 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_total.h"

int		ft_is_space(char *str)
{
	if (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f'
			|| *str == '\r')
		return (1);
	else
		return (0);
}

int		ft_is_non_printable(char *str)
{
	if (*str < 32 || *str > 126)
		return (1);
	else
		return (0);
}

int		ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_full_check(t_data *data, char *argv)
{
	int		i;

	i = 0;
	while (i < mal_len())
	{
		if (ft_strcmp(data[i].key, argv) == 0)
		{
			ft_print(data[i].value, 0);
			return (1);
		}
		i++;
	}
	return (0);
}
