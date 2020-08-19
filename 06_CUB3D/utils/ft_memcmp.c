/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:19:45 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:19:46 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t			i;
	unsigned char	p1;
	unsigned char	p2;

	i = 0;
	while (i < n)
	{
		p1 = *((unsigned char *)ptr1 + i);
		p2 = *((unsigned char *)ptr2 + i);
		if (p1 != p2)
			return (p1 - p2);
		i++;
	}
	return (0);
}
