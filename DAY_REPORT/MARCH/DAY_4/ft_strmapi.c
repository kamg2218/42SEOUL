/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:54:52 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:54:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	j = 0;
	while (s[j])
	{
		str[j] = f(j, s[j]);
		j++;
	}
	str[j] = 0;
	return (str);
}