/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:09:06 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 13:52:12 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
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
