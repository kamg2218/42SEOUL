/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:49:55 by hyoon             #+#    #+#             */
/*   Updated: 2020/01/28 20:50:04 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		temp;
	int		i;

	i = -1;
	while (++i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
		}
		else
			continue ;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;

	i = size + 1;
	while (--i > 1)
		ft_rev_int_tab(tab, i);
}
