/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:30:04 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/09 23:39:49 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_total.h"

int		main(int argc, char *argv[])
{
	t_data	*data;

	if (argc < 2 || ft_numeric_check(argv[1]) != 0)
	{
		ft_print("Error", 0);
		return (0);
	}
	data = ft_initialize();
	if (data == 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	ft_cut(data, argv[1]);
	free(data);
	return (0);
}
