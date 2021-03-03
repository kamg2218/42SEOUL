/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_in_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:20:10 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:20:11 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			num_in_line(char *line)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (ft_isalnum(line[i]) == 4)
			return (1);
	}
	return (0);
}