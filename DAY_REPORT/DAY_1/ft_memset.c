/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:50:58 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:50:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memset(void *ptr, int value, unsigned int num)
{
  unsigned int  i;

  i = 0;
  while (i < num)
  {
    *((unsigned char *)ptr + i) = value;
    i++;
  }
  return (ptr);
}