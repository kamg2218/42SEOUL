/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:22:14 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/05 19:22:18 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		i;
	int		result;

	i = -1;
	result = 1;
	if (power < 0)
		return (0);
	while (++i < power)
		result *= nb;
	return (result);
}
