#include "philo_one.h"

int				ft_minus(const char *str, int *minus)
{
	int			i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*minus = -1;
		else if (str[i] == '+')
			*minus = 1;
		i++;
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long long	result;

	minus = 1;
	result = 0;
	i = ft_minus(str, &minus);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result * minus > 2147483647)
			return (-1);
		else if (result * minus < -2147483648)
			return (0);
		else
			result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * minus);
}

int				str_error(char *str, int re)
{
	printf("%s", str);
	clear();
	return (re);
}

int				clear(void)
{
	int			cnt;

	if (g_argu.mutex)
	{
		cnt = 0;
		while (cnt < g_argu.num)
			pthread_mutex_destroy(&g_argu.mutex[cnt++]);
		free(g_argu.mutex);
		pthread_mutex_destroy(&g_argu.msg);
	}
	if (g_argu.thread)
		free(g_argu.thread);
	return (0);
}

int64_t				get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
