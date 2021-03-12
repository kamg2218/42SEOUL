/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:31:52 by hyoon             #+#    #+#             */
/*   Updated: 2021/03/12 13:49:18 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			*get_death(void *philo)
{
	int			cnt;
	t_philo		*ph;

	ph = (t_philo *)philo;
	sem_wait(g_argu.monitor);
	cnt = 0;
	while (cnt < g_argu.num)
		kill(g_argu.pid[cnt++], SIGKILL);
	sem_unlink("monitor");
	return (NULL);
}

void			*get_full(void *philo)
{
	int			cnt;
	t_philo		*ph;

	ph = (t_philo *)philo;
	cnt = -1;
	while (++cnt < g_argu.num)
		sem_wait(g_argu.full);
	massage(0, 0, FULL);
	cnt = 0;
	while (cnt < g_argu.num)
		kill(g_argu.pid[cnt++], SIGKILL);
	sem_unlink("full");
	return (NULL);
}

void			*monitor(void *philo)
{
	int64_t		cur;
	t_philo		*ph;

	ph = (t_philo *)philo;
	while (g_argu.death == 0)
	{
		if (g_argu.must_eat && g_argu.must_eat == ph->eat_cnt)
			sem_post(g_argu.full);
		if (g_argu.die < (cur = get_time() - ph->eat))
		{
			if (!(massage(cur, ph->order, DIE)))
				return (NULL);
			g_argu.death = ph->order;
		}
	}
	return (NULL);
}
