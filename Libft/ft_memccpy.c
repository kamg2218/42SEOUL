/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:08:40 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/11 02:08:43 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)src + i) == c)
			return ((unsigned char *)dest + i + 1);
		else if (*((unsigned char *)src + i) == '\0')
			break ;
		i++;
	}
	return (0);
}
