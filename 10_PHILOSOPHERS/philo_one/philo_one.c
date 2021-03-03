#include "philo_one.h"

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
		if (pthread_mutex_init(&mutex[cnt++], NULL))
			return (0);
	}
	return (1);
}

void			philo_init(t_philo *philo)
{
	philo->order = 0;
	philo->eat = 0;
	philo->think = 0;
	philo->sleep = 0;
}

int				make_thread(void)
{
	int			cnt;

	cnt = 0;
	while (cnt < g_argu.num)
	{
		if (!(pthread_create(&g_argu.mutex[cnt], NULL, , )))
			return (0);
		pthread_detach(g_argu.mutex[cnt]);
		++cnt;
	}
	return (1);
}

int				main(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (str_error("Error: Argument!!\n", 0));
	if (!(argu_init(argc, argv)))
		return (str_error("Error: initialize error\n"));
	if (!(make_thread()))
		return (str_error("Error: fail to make thread\n"));
}
