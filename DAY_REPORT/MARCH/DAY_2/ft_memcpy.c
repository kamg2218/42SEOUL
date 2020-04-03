/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:53:07 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:53:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *destination, const void *source, unsigned int num)
{
	unsigned int	i;
	
	i = 0;
	while (i < num)
	{
		if (*((char *)source + i) == 0)
			*((char *)destination + i) = 0;
		else
			*((char *)destination + i) = *((char *)source + i);
		i++;
	}
	return (destination);
}