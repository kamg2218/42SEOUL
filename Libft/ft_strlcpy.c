/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:23:28 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/11 02:23:31 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j])
		j++;
	if (n == 0)
		return (j);
	i = 0;
	while (i < n - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (j);
}
