/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:53:11 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:53:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src < dest)
			*((char *)dest + (n - i - 1)) = *((char *)src + (n - i - 1));
		else
			*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}