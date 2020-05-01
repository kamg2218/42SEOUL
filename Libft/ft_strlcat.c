/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:23:13 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/11 02:23:16 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	while (src[j])
		j++;
	i = 0;
	while (dst[i])
		i++;
	if (n <= i)
		return (j + n);
	else
		k = j + i;
	j = 0;
	while (j < n - i - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (k);
}
