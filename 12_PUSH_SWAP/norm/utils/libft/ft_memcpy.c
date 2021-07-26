/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:09:19 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/11 02:09:34 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *source, size_t num)
{
	size_t	i;

	if (!dst && !source)
		return (0);
	i = 0;
	while (i < num)
	{
		if (*((unsigned char *)source + i) == 0)
			*((unsigned char *)dst + i) = 0;
		else
			*((unsigned char *)dst + i) = *((unsigned char *)source + i);
		i++;
	}
	return (dst);
}
