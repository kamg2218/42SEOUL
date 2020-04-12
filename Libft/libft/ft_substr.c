/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:25:32 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/11 02:25:34 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		if (!s[i + start])
			break ;
		else
			sub[i] = s[i + start];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
