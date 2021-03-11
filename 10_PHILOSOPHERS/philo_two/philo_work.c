/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:44:19 by hyoon             #+#    #+#             */
/*   Updated: 2021/03/11 20:57:10 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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

int					make_thread(void)
{
	int				cnt;
	t_philo			*philo;
	pthread_t		*thread;

	if (!(philo = (t_philo *)malloc(sizeof(t_philo) * g_argu.num)))
		return (0);
	g_argu.start = get_time();
	thread = g_argu.thread;
	cnt = 0;
	while (cnt < g_argu.num)
	{
		philo_init(&philo[cnt], cnt);
		if ((pthread_create(&thread[cnt], NULL, routine, (void *)&philo[cnt])))
			return (0);
		pthread_detach(thread[cnt]);
		usleep(10);
		++cnt;
	}
	while (g_argu.death == 0)
		usleep(10);
	massage(get_time() - g_argu.start, g_argu.death, DIE);
	return (1);
}

void				eat_meal(t_philo *philo)
{
	int64_t			dst;

	sem_wait(g_argu.sem);
	sem_wait(g_argu.sem);
	if (!(massage(get_time() - g_argu.start, philo->order, FORK)))
		return ;
	philo->eat = get_time();
	if (!(massage(philo->eat - g_argu.start, philo->order, EAT)))
		return ;
	dst = philo->eat + g_argu.eat;
	while (dst > get_time())
		usleep(10);
	sem_post(g_argu.sem);
	sem_post(g_argu.sem);
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
