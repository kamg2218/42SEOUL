/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:25:47 by hyoon             #+#    #+#             */
/*   Updated: 2021/03/11 20:25:50 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int				make_monitor(void)
{
	pthread_t	monitor;
	pthread_t	full;

	if (pthread_create(&monitor, NULL, get_death, NULL))
		return (0);
	pthread_detach(monitor);
	if (pthread_create(&full, NULL, get_full, NULL))
		return (0);
	pthread_detach(full);
	cnt = -1;
	while (++cnt < g_argu.num)
		waitpid(0, NULL, 0);
	return (1);
}

int				make_thread(void)
{
	int			cnt;
	t_philo		philo;

	g_argu.start = get_time();
	cnt = 0;
	while (cnt < g_argu.num)
	{
		g_argu.pid[cnt] = fork();
		if (g_argu.pid[cnt] == -1)
			exit(0);
		else if (g_argu.pid[cnt] == 0)
		{
			philo_init(&philo, cnt);
			routine(&philo);
			exit(0);
		}
		++cnt;
	}
	if (!(make_monitor()))
		return (0);
	return (1);
}

void			eat_meal(t_philo *philo)
{
	int64_t		dst;

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

void			sleep_well(t_philo *philo)
{
	int64_t		cur;
	int64_t		dst;

	if (!(massage((cur = get_time()) - g_argu.start, philo->order, SLEEP)))
		return ;
	dst = cur + g_argu.sleep;
	while (dst > get_time())
		usleep(10);
}

void			*routine(t_philo *philo)
{
	if (pthread_create(&philo->monitor, NULL, monitor, (void *)philo))
		return (NULL);
	pthread_detach(philo->monitor);
	while (g_argu.death == 0)
	{
		eat_meal(philo);
		sleep_well(philo);
		if (!(massage(get_time() - g_argu.start, philo->order, THINK)))
			break ;
	}
	return (NULL);
}
