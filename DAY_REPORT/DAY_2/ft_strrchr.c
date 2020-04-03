/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:53:24 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:53:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *str, int c)
{
	unsigned int    i;
	unsigned int    result;

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