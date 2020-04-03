/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:52:54 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:52:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		if (*((char *)src + i) == c)
			return ((char *)dest + i + 1);
		else if (*((char *)src + i) == '\0')
			break;
		i++;
	}
	return (0);
}