/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:52:48 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:52:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_isspace(char c)
{
	if (c == ' ' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		minus;
	int		result;

	i = 0;
	minus = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		else
			minus = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * minus);
}