/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:23:28 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/13 12:23:33 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	while (src[i])
		i++;
	ptr = (char*)malloc(i + 1);
	if (ptr == NULL)
		return (0);
	j = 0;
	while (j < i)
	{
		ptr[j] = src[j];
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}
