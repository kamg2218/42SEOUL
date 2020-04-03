/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:35:54 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/10 15:36:45 by hyoon            ###   ########.fr       */
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

void	ft_swap(int i, int j, char *argv[])
{
	int		a;
	char	*temp;

	a = 0;
	while (argv[i][a] != 0 || argv[j][a] != 0)
	{
		if (argv[i][a] > argv[j][a])
		{
			temp = argv[i];
			argv[i] = argv[j];
			argv[j] = temp;
		}
		else if (argv[i][a] == argv[j][a])
			a++;
		else
			return ;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			ft_swap(i, j, argv);
			j++;
		}
		i++;
	}
	ft_print(argc, argv);
	return (0);
}
