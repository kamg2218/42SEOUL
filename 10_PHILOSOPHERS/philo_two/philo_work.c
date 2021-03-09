#include "philo_two.h"

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
		//usleep(10);
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

	if (sem_wait(g_argu.sem))
		return ;
	if (sem_wait(g_argu.sem))
		return ;
	if (!(massage(get_time() - g_argu.start, philo->order, FORK)))
		return ;
	philo->eat = get_time();
	if (!(massage(philo->eat - g_argu.start, philo->order, EAT)))
		return ;
	dst = philo->eat + g_argu.eat;
	while (dst > get_time())
		usleep(10);
	if (sem_post(g_argu.sem))
		return ;
	if (sem_post(g_argu.sem))
		return ;
	philo->eat_cnt += 1;
}

void				sleep_well(t_philo *philo)
{
	int64_t			cur;
	int64_t			dst;

	if (!(massage((cur = get_time()) - g_argu.start, philo->order, SLEEP)))
		return ;
	dst = cur + g_argu.sleep;
	//dst = philo->eat + g_argu.eat + g_argu.sleep;
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
