/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:53:15 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:53:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
        return (str + i);
	return (0);
}