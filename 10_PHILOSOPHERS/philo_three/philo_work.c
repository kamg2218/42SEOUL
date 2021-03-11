#include "philo_three.h"

int				make_thread(void)
{
	int			cnt;
	int			status;
	t_philo		philo;
	pid_t		pid;

	g_argu.start = get_time();
	cnt = 0;
	while (cnt < g_argu.num)
	{
		pid = fork();
		if (pid == -1)
			exit(0);
		else if (pid == 0)
		{
			philo_init(&philo, cnt);
			routine(&philo);
			exit(0);
		}
		else
			++cnt;
	}
	cnt = -1;
	while (++cnt < g_argu.num)
	{
		waitpid(0, &status, 0);
		printf("status = %d\n", status);
	}
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
