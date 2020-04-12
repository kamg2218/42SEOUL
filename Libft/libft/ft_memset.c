/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:09:57 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/11 02:09:59 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		*((unsigned char *)ptr + i) = value;
		i++;
	}
	return (ptr);
}
