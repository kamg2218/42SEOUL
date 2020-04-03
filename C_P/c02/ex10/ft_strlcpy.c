/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:02:36 by hyoon             #+#    #+#             */
/*   Updated: 2020/01/31 10:08:50 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (src[j] != 0)
		j++;
	if (size == 0)
	{
		dest[0] = '\0';
		return (j);
	}
	i = 0;
	while (i < size)
	{
		if (src[i] == '\0')
		{
			dest[i] = '\0';
			return (j);
		}
		else
			dest[i] = src[i];
		i++;
	}
	dest[i - 1] = '\0';
	return (j);
}
