/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:34:09 by hyoon             #+#    #+#             */
/*   Updated: 2021/03/13 20:46:05 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int					massage(int64_t time, int order, int msg)
{
	pthread_mutex_lock(&g_argu.msg);
	if (g_argu.death != 0)
	{
		pthread_mutex_unlock(&g_argu.msg);
		return (0);
	}
	if (msg == EAT)
		printf("%lldms %d is eating\n", time, order);
	else if (msg == SLEEP)
		printf("%lldms %d is sleeping\n", time, order);
	else if (msg == THINK)
		printf("%lldms %d is thinking\n", time, order);
	else if (msg == DIE)
	{
		printf("%lldms %d died\n", time, order);
		g_argu.death = order;
	}
	else if (msg == FORK)
		printf("%lldms %d has taken a fork\n", time, order);
	else if (msg == FULL)
		printf("All philosopher is full\n");
	pthread_mutex_unlock(&g_argu.msg);
	return (1);
}

void				*monitor(void *philo)
{
	int64_t			cur;
	t_philo			*ph;

	ph = (t_philo *)philo;
	while (g_argu.death == 0)
	{
		if (g_argu.must_eat && g_argu.must_eat == ph->eat_cnt)
			g_argu.full += 1;
		if (g_argu.full == g_argu.num)
		{
			if (!(massage(0, ph->order, FULL)))
				return (NULL);
			g_argu.death = g_argu.num + 1;
		}
		if (g_argu.die < (cur = get_time() - ph->eat))
			massage(cur, ph->order, DIE);
	}
	return (NULL);
}

int					main(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (str_error("Error: Argument!!\n", 0));
	if (!(argu_init(argc, argv)))
		return (str_error("Error: argument error\n", 0));
	if (!(pointer_init()))
		return (str_error("Error: malloc error\n", 0));
	if (!(make_thread()))
		return (str_error("Error: fail to make thread\n", 0));
	clear();
	return (0);
}
