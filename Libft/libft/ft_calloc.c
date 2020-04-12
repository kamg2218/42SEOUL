/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:04:21 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/11 02:04:24 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;
	size_t	j;

	i = malloc(size * count);
	if (i == NULL)
		return (0);
	j = 0;
	while (j < size * count)
	{
		*((unsigned char *)i + j) = 0;
		j++;
	}
	return (i);
}
