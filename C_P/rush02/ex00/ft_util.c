/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:29:57 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/09 23:38:37 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_total.h"

void	ft_print(char *str, int i)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	if (i == 1)
		write(1, " ", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (s1[i] - s2[i]);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int		result;
	int		j;

	j = 0;
	result = 0;
	while (j < 2)
	{
		result = result * 10 + (str[j] - '0');
		j++;
	}
	return (result);
}

void	ft_sam(t_data *data, char *str, int n)
{
	int		i;
	int		num;

	if (ft_full_check(data, str))
		return ;
	if (str[0] != '0')
	{
		i = str[0] - '0';
		ft_print(data[i].value, 1);
		write(1, "hundred ", 8);
	}
	num = ft_atoi(&str[1]);
	if (num < 20)
		ft_print(data[num + 1].value, 1);
	else
	{
		ft_print(data[num / 10 + 18].value, 0);
		if (num % 10 != 0)
		{
			write(1, " ", 1);
			ft_print(data[num % 10].value, 0);
		}
	}
	ft_sam_check(data, n);
	return ;
}
