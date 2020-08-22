/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:20:02 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:20:03 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			ft_strlen(char *string)
{
	int		i;

	if (string == NULL)
		return (0);
	i = 0;
	while (string[i])
		i++;
	return (i);
}
