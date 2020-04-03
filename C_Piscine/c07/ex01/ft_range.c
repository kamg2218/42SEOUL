/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:23:40 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/13 12:23:56 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_range(int min, int max)
{
	int		i;
	int		minus;
	int		*i_ar;

	minus = max - min;
	if (minus <= 0)
	{
		minus = 1;
		min = 0;
	}
	i_ar = (int*)malloc(minus * 4);
	i = 0;
	while (i < minus)
	{
		i_ar[i] = min + i;
		i++;
	}
	return (i_ar);
}
