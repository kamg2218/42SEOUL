/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:53:02 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:53:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_memcmp(const void *ptr1, const void *ptr2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*((char *)ptr1 + i) != *((char *)ptr2 + i))
			return (*((char *)ptr1 + i) - *((char *)ptr2 + i));
		i++;
	}
	return (0);
}