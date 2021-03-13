/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:43:17 by hyoon             #+#    #+#             */
/*   Updated: 2021/03/13 20:45:27 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int					make_thread(void)
{
	int				cnt;
	t_philo			*philo;
	pthread_t		*thread;

	philo = g_argu.philo;
	g_argu.start = get_time();
	thread = g_argu.thread;
	cnt = 0;
	while (cnt < g_argu.num)
	{
		philo_init(&philo[cnt], cnt);
		if ((pthread_create(&thread[cnt], NULL, routine, (void *)&philo[cnt])))
			return (0);
		pthread_detach(thread[cnt]);
		cnt += 2;
		if ((cnt == g_argu.num && g_argu.num % 2 == 0)
				|| (g_argu.num % 2 && cnt == g_argu.num + 1))
			cnt = 1;
	}
	while (g_argu.death == 0)
		usleep(1);
	return (1);
}

void				eat_meal(t_philo *philo)
{
	int64_t			dst;

	pthread_mutex_lock(&g_argu.mutex[philo->order - 1]);
	pthread_mutex_lock(&g_argu.mutex[philo->right]);
	if (!(massage(get_time() - g_argu.start, philo->order, FORK)))
		return ;
	philo->eat = get_time();
	if (!(massage(philo->eat - g_argu.start, philo->order, EAT)))
		return ;
	dst = philo->eat + g_argu.eat;
	while (dst > get_time())
		usleep(10);
	pthread_mutex_unlock(&g_argu.mutex[philo->order - 1]);
	pthread_mutex_unlock(&g_argu.mutex[philo->right]);
	philo->eat_cnt += 1;
}

void				sleep_well(t_philo *philo)
{
	int64_t			cur;
	int64_t			dst;

	if (!(massage((cur = get_time()) - g_argu.start, philo->order, SLEEP)))
		return ;
	dst = cur + g_argu.sleep;
	while (dst > get_time())
		usleep(10);
}

void				*routine(void *philo)
{
	t_philo			*ph;

	ph = (t_philo *)philo;
	if (pthread_create(&ph->monitor, NULL, monitor, philo))
		return (NULL);
	pthread_detach(ph->monitor);
	while (g_argu.death == 0)
	{
		eat_meal(ph);
		sleep_well(ph);
		if (!(massage(get_time() - g_argu.start, ph->order, THINK)))
			break ;
	}
	return (NULL);
}
