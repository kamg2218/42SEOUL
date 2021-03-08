#include "philo_one.h"

int				make_thread(void)
{
	int			cnt;
	t_philo		*philo;

	if (!(g_argu.thread = malloc(sizeof(pthread_t) * g_argu.num)))
		return (0);
	if (!(philo = (t_philo *)malloc(sizeof(t_philo) * g_argu.num)))
		return (0);
	g_argu.start = get_time();
	cnt = 0;
	while (cnt < g_argu.num)
	{
		philo_init(&philo[cnt], cnt);
		if ((pthread_create(&g_argu.thread[cnt], NULL, routine, (void *)&philo[cnt])))
			return (0);
		pthread_detach(g_argu.thread[cnt]);
		usleep(1);
		cnt += 2;
		if ((cnt == g_argu.num && g_argu.num % 2 == 0)
				|| (g_argu.num % 2 && cnt == g_argu.num + 1))
			cnt = 1;
	}
	while (g_argu.death == 0)
		usleep(1);
	massage(get_time() - g_argu.start, g_argu.death, DIE);
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
	int64_t			dst;

	if (!(massage(get_time() - g_argu.start, philo->order, SLEEP)))
		return ;
	dst = philo->eat + g_argu.eat + g_argu.sleep;
	while (dst > get_time())
		usleep(10);
}

void			*routine(void *philo)
{
	t_philo		*ph;

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
