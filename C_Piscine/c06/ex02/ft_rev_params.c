/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:34:43 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/10 15:35:48 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	char	*temp;

	i = 1;
	while (i < argc / 2 + 1)
	{
		temp = argv[i];
		argv[i] = argv[argc - i];
		argv[argc - i] = temp;
		i++;
	}
	ft_print(argc, argv);
	return (0);
}
