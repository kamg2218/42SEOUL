#include "philo_one.h"

int64_t				get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int				argu_init(int argc, char *argv[])
{
	int			cnt;

	g_argu.num = ft_atoi(argv[1]);
	g_argu.die = ft_atoi(argv[2]);
	g_argu.eat = ft_atoi(argv[3]);
	g_argu.sleep = ft_atoi(argv[4]);
	g_argu.death = 0;
	g_argu.full = 0;
	g_argu.must_eat = 0;
	if (argc == 6)
		g_argu.must_eat = ft_atoi(argv[5]);
	if (!(g_argu.mutex = malloc(sizeof(pthread_mutex_t) * g_argu.num)))
		return (0);
	cnt = 0;
	while (cnt < g_argu.num)
	{
		if (pthread_mutex_init(&g_argu.mutex[cnt++], NULL))
			return (0);
	}
	if (pthread_mutex_init(&g_argu.msg, NULL))
		return (0);
	return (1);
}

void			philo_init(t_philo *philo, int cnt)
{
	philo->eat_cnt = 0;
	philo->monitor = 0;	
	philo->order = cnt + 1;
	philo->right = 0;
	if (philo->right < g_argu.num)
		philo->right = cnt + 1;
	philo->eat = g_argu.start;
}

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
		if ((pthread_create(&g_argu.thread[cnt], NULL, do_something, (void *)&philo[cnt])))
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

//void			print_death(void)
//{
//	if (g_argu.full == g_argu.num)
//		return ;
//	if (!(massage(get_time() - g_argu.start, g_argu.death, DIE)))
//		return ;
//}

void			*monitor(void *philo)
{
	int64_t		cur;
	t_philo		*ph;

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

void			*do_something(void *philo)
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

int				massage(int64_t time, int order, int msg)
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

int				main(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (str_error("Error: Argument!!\n", 0));
	if (!(argu_init(argc, argv)))
		return (str_error("Error: initialize error\n", 0));
	if (!(make_thread()))
		return (str_error("Error: fail to make thread\n", 0));
	clear();
	return (0);
}
