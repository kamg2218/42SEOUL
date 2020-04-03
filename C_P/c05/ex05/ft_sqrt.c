/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:05:11 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/06 18:05:27 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		i;

	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0 && nb / i == i)
			return (i);
		i++;
	}
	return (0);
}
