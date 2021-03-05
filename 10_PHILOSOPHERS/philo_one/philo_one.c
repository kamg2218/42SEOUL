#include "philo_one.h"

int64_t				get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int64_t				get_timediff(int64_t time, int64_t start)
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

void			philo_init(t_philo *philo)
{
	philo->order = 0;
	philo->eat = 0;
	philo->eat_cnt = 0;
	philo->start = 0;
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
		if ((pthread_create(&g_argu.thread[cnt], NULL, do_something, (void *)&philo[cnt])))
			return (0);
		pthread_detach(g_argu.thread[cnt++]);
		usleep(1000);
	}
	while (g_argu.death == 0
			|| (g_argu.must_eat && g_argu.full < g_argu.num))
		usleep(100);
	return (1);
}

void				eat_meal(t_philo *philo)
{
	int				num;
	int64_t			dst;

	pthread_mutex_lock(&g_argu.mutex[philo->order - 1]);
	num = philo->order;
	if (num >= g_argu.num)
		num = 0;
	pthread_mutex_lock(&g_argu.mutex[num]);
	printf("%lldms %d has taken a fork\n", get_timediff(get_time(), philo->start), philo->order);
	philo->eat = get_time();
	printf("%lldms %d is eating\n", get_timediff(philo->eat, philo->start), philo->order);
	dst = philo->eat + g_argu.eat;
	while (dst > get_time())
		usleep(1000);
	philo->eat_cnt += 1;
	pthread_mutex_unlock(&g_argu.mutex[philo->order - 1]);
	pthread_mutex_unlock(&g_argu.mutex[num]);
}

void				sleep_well(t_philo *philo)
{
	int64_t			dst;

	if (g_argu.death != 0)
		return ;
	printf("%lldms %d is sleeping\n", get_timediff(get_time(), philo->start), philo->order);
	dst = philo->eat + g_argu.eat + g_argu.sleep;
	while (dst > get_time())
		usleep(1000);
}

void			think_philo(t_philo *philo)
{
	if (g_argu.death != 0)
		return ;
	printf("%lldms %d is thinking\n", get_timediff(get_time(), philo->start), philo->order);
}

void			print_death(t_philo *philo)
{
	if (g_argu.full == g_argu.num)
		return ;
	if (g_argu.death == philo->order)
		printf("%lld %d died\n", get_timediff(get_time(), philo->start), philo->order);
}

void			*monitor(void *philo)
{
	int64_t		t;
	t_philo		*ph;

	ph = (t_philo *)philo;
	while (g_argu.death == 0)
	{
		if (g_argu.must_eat && g_argu.must_eat == ph->eat_cnt)
			g_argu.full += 1;
		if (g_argu.full >= g_argu.num)
			g_argu.death = ph->order;
		t = ph->eat;
		if (ph->eat == 0)
			t = ph->start;
		if (g_argu.die <= get_timediff(get_time(), t))
			g_argu.death = ph->order;
	}
	return (NULL);
}

void			*do_something(void *philo)
{
	t_philo		*ph;

	ph = (t_philo *)philo;
	ph->start = get_time();
	if (pthread_create(&ph->monitor, NULL, monitor, philo))
		return (NULL);
	pthread_detach(ph->monitor);
	while (g_argu.death == 0)
	{
		eat_meal(ph);
		sleep_well(ph);
		think_philo(ph);
	}
	print_death(ph);
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
	if (g_argu.full == g_argu.num)
		printf("All philosopher is full\n");
	else
		printf("dead philosopher is %d\n", g_argu.death);
	clear();
	return (0);
}
