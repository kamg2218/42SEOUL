/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:57:41 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/12 15:01:35 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_is_valid_base(char *str)
{
	int		i;
	int		j;
	int		len;

	len = ft_str_len(str);
	if (len <= 1)
		return (0);
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\n' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\r'
				|| str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_num(char str, char *base)
{
	int		i;

	i = 0;
	while (i < ft_str_len(base))
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (i);
}

int		ft_check_minus(char *str)
{
	int		i;
	int		minus;

	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\n' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	return (minus);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		n;
	int		b_len;
	int		result;

	i = 0;
	b_len = ft_str_len(base);
	result = 0;
	if (!ft_is_valid_base(base))
		return (0);
	while (str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\n' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\r'
				|| str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		n = ft_find_num(str[i], base);
		if (n < b_len)
			result = result * b_len + n;
		else
			return (result * ft_check_minus(str));
		i++;
	}
	return (result * ft_check_minus(str));
}
