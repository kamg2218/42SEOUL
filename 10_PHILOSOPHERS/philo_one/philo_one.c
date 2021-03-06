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
	return (1);
}

void			philo_init(t_philo *philo, int cnt)
{
	philo->eat_cnt = 0;
	philo->start = 0;
	philo->monitor = 0;	
	philo->order = cnt + 1;
	philo->eat = g_argu.start;
	philo->right = 0;
	if (philo->right < g_argu.num)
		philo->right = cnt + 1;
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
	print_death();
	return (1);
}

void				eat_meal(t_philo *philo)
{
	int64_t			dst;

	pthread_mutex_lock(&g_argu.mutex[philo->order - 1]);
	pthread_mutex_lock(&g_argu.mutex[philo->right]);
	printf("%lldms %d has taken a fork\n", get_time() - g_argu.start, philo->order);
	philo->eat = get_time();
	printf("%lldms %d is eating\n", philo->eat - g_argu.start, philo->order);
	dst = philo->eat + g_argu.eat;
	while (dst >= get_time())
		usleep(1);
	philo->eat_cnt += 1;
	pthread_mutex_unlock(&g_argu.mutex[philo->order - 1]);
	pthread_mutex_unlock(&g_argu.mutex[philo->right]);
}

void				sleep_well(t_philo *philo)
{
	int64_t			dst;
	int64_t			sleep;

	if (g_argu.death != 0)
		return ;
	sleep = get_time();
	printf("%lldms %d is sleeping\n", sleep - g_argu.start, philo->order);
	dst = sleep + g_argu.sleep;
	while (dst >= get_time())
		usleep(1);
}

void			print_death(void)
{
	if (g_argu.full == g_argu.num)
		return ;
	if (g_argu.death)
		printf("%lldms %d died\n", get_time() - g_argu.start, g_argu.death);
}

void			*monitor(void *philo)
{
	t_philo		*ph;

	ph = (t_philo *)philo;
	while (g_argu.death == 0)
	{
		if (g_argu.must_eat && g_argu.must_eat == ph->eat_cnt)
			g_argu.full += 1;
		if (g_argu.full == g_argu.num)
		{
			g_argu.death = g_argu.num + 1;
			printf("All philosopher is full\n");
			break ;
		}
		if (g_argu.die < get_time() - ph->eat)
			g_argu.death = ph->order;
	}
	return (NULL);
}

void			*do_something(void *philo)
{
	int64_t		dst;
	int64_t		sleep;
	t_philo		*ph;

	ph = (t_philo *)philo;
	if (pthread_create(&ph->monitor, NULL, monitor, philo))
		return (NULL);
	pthread_detach(ph->monitor);
	while (g_argu.death == 0)
	{
		eat_meal(ph);
		//sleep_well(ph);
		sleep = get_time();
		printf("%lldms %d is sleeping\n", sleep - g_argu.start, ph->order);
		dst = sleep + g_argu.sleep;
		while (dst >= get_time())
			usleep(1);
		printf("%lldms %d is thinking\n", get_time() - g_argu.start, ph->order);
	}
	return (NULL);
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
