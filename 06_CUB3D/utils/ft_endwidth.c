/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:19:21 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:19:29 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			ft_endwidth(char *str1, char *str2)
{
	int		i;
	int		len1;
	int		len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len2 > len1)
		return (0);
	i = 0;
	while (i < len2)
	{
		i++;
		if (str1[len1 - i] != str2[len2 - i])
			return (0);
	}
	return (1);
}
