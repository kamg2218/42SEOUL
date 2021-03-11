/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:31:21 by hyoon             #+#    #+#             */
/*   Updated: 2021/03/11 20:38:43 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int				ft_minus(const char *str, int *minus)
{
	int			i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*minus = -1;
		else if (str[i] == '+')
			*minus = 1;
		i++;
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long long	result;

	minus = 1;
	result = 0;
	i = ft_minus(str, &minus);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result * minus > 2147483647)
			return (-1);
		else if (result * minus < -2147483648)
			return (0);
		else
			result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * minus);
}

int				str_error(char *str, int re)
{
	printf("%s", str);
	sem_unlink("semaphore");
	sem_unlink("msg");
	if (g_argu.pid)
		free(g_argu.pid);
	return (re);
}

int64_t			get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
