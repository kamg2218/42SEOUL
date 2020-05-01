/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:24:34 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/11 02:24:36 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(char *str1, char *str2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	l;

	l = 0;
	while (str2[l])
		l++;
	if (!l)
		return (str1);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < l && i + j < n)
		{
			if (str1[i + j] != str2[j])
				j = l + 1;
			j++;
		}
		if (j == l)
			return (str1 + i);
		i++;
	}
	return (0);
}
