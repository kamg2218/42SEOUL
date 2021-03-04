#include "philo_one.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

unsigned long		get_timediff(unsigned long time, unsigned long start)
{
	return (time - start);
}

int				argu_init(int argc, char *argv[])
{
	int			cnt;

	g_argu.num = ft_atoi(argv[1]);
	g_argu.die = ft_atoi(argv[2]);
	g_argu.eat = ft_atoi(argv[3]);
	g_argu.sleep = ft_atoi(argv[4]);
	g_argu.must_eat = 0;
	g_argu.death = 0;
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

void			philo_init(t_philo *philo)
{
	philo->order = 0;
	philo->eat = 0;
}

int				make_thread(void)
{
	int			cnt;
	t_philo		*philo;

	if (!(g_argu.thread = malloc(sizeof(pthread_t) * g_argu.num)))
		return (0);
	if (!(philo = (t_philo *)malloc(sizeof(t_philo) * g_argu.num)))
		return (0);
	cnt = 0;
	while (cnt < g_argu.num)
	{
		philo_init(&philo[cnt]);
		philo[cnt].order = cnt + 1;
		philo[cnt].start = get_time();
		if ((pthread_create(&g_argu.thread[cnt], NULL, do_something, (void *)&philo[cnt])))
			return (0);
		pthread_detach(g_argu.thread[cnt++]);
		usleep(500000);
	}
	return (1);
}

void				eat_meal(t_philo *philo)
{
	int				num;
	unsigned long	dst;

	pthread_mutex_lock(&g_argu.mutex[philo->order - 1]);
	num = philo->order;
	if (num >= g_argu.num)
		num = 0;
	pthread_mutex_lock(&g_argu.mutex[num]);
	printf("%lums %d has taken a fork\n", get_timediff(get_time(), philo->start), philo->order);
	if (g_argu.must_eat > g_argu.eat)
		g_argu.death = philo->order;
	else if (g_argu.die < g_argu.eat)
		g_argu.death = philo->order;
	else
	{
		philo->eat = get_time();
		printf("%lums %d is eating\n", get_timediff(philo->eat, philo->start), philo->order);
		dst = philo->eat + g_argu.eat;
		while (dst > get_time())
			usleep(100);
		//usleep(g_argu.eat * 1000);
	}
	pthread_mutex_unlock(&g_argu.mutex[philo->order - 1]);
	pthread_mutex_unlock(&g_argu.mutex[num]);
}

void				sleep_well(t_philo *philo)
{
	unsigned long	dst;

	if (g_argu.death != 0)
		return ;
	if (g_argu.sleep > g_argu.die)
		g_argu.death = philo->order;
	else
	{
		printf("%lums %d is sleeping\n", get_timediff(get_time(), philo->start), philo->order);
		dst = philo->eat + g_argu.eat + g_argu.sleep;
		while (dst > get_time())
			usleep(100);
		//usleep(g_argu.sleep * 1000);
	}
}

void			think_philo(t_philo *philo)
{
	if (g_argu.death != 0)
		return ;
	printf("%lums %d is thinking\n", get_timediff(get_time(), philo->start), philo->order);
}

void			*do_something(void *philo)
{
	t_philo		*ph;

	ph = (t_philo *)philo;
	printf("philo %d starts!\n", ph->order);
	while (g_argu.death == 0)
	{
		eat_meal(ph);
		sleep_well(ph);
		think_philo(ph);
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
	printf("philosopher %d died.\n", g_argu.death);
	clear();
	return (0);
}
