/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:29:11 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/04 17:54:31 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = str_len(dest);
	j = str_len(src);
	k = 0;
	if (size < i)
		return (size + j);
	while (i + k + 1 < size && src[k])
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (i + j);
}
