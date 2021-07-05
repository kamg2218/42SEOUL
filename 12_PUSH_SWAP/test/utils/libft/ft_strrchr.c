/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:24:59 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/11 02:25:01 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(char *str, int c)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == c)
			result = i;
		i++;
	}
	if (c == '\0')
		return (str + i);
	else if (result != 0 || str[0] == c)
		return (str + result);
	else
		return (0);
}
