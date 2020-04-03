/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:53:54 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:53:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

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