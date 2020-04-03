/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:54:08 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:54:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char *str1, char *str2, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	L;

	L = 0;
	while (str2[L])
		L++;
	if (!L)
		return (str1);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < L && i + j < n)
		{
			if (str1[i + j] != str2[j])
				j = L + 1;
			j++;
		}
		if (j == L)
			return (str1 + i);
		i++;
	}
	return (0);
}