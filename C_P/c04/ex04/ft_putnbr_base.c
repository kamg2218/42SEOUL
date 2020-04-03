/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:54:26 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/11 17:17:27 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		if (str[i] == '+' || str[i] == '-')
			return (0);
		else if (str[i] < 33 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;

	len = ft_str_len(base);
	if (!ft_is_valid_base(base))
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / len, base);
		write(1, &base[-1 * (nbr % len)], 1);
		return ;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= len)
	{
		ft_putnbr_base(nbr / len, base);
		nbr = base[nbr % len];
	}
	else
		nbr = base[nbr];
	write(1, &nbr, 1);
}
