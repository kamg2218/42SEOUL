/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:37:17 by hyoon             #+#    #+#             */
/*   Updated: 2021/03/13 21:14:33 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int				check_argu(void)
{
	if (g_argu.num <= 0)
		return (0);
	else if (g_argu.die < 0 || g_argu.eat < 0
			|| g_argu.sleep < 0 || g_argu.must_eat < 0)
		return (0);
	return (1);
}

int				argu_init(int argc, char *argv[])
{
	g_argu.num = ft_atoi(argv[1]);
	g_argu.die = ft_atoi(argv[2]);
	g_argu.eat = ft_atoi(argv[3]);
	g_argu.sleep = ft_atoi(argv[4]);
	g_argu.death = 0;
	g_argu.full = 0;
	g_argu.must_eat = 0;
	if (argc == 6)
		g_argu.must_eat = ft_atoi(argv[5]);
	sem_unlink("semaphore");
	if ((g_argu.sem = sem_open("semaphore", O_CREAT, 0644, g_argu.num)) == NULL)
		return (0);
	sem_unlink("msg");
	if ((g_argu.msg = sem_open("msg", O_CREAT, 0644, 1)) == NULL)
		return (0);
	if (!(g_argu.thread = malloc(sizeof(pthread_t) * g_argu.num)))
		return (0);
	if (!(g_argu.philo = malloc(sizeof(t_philo) * g_argu.num)))
		return (0);
	return (1);
}

void			philo_init(t_philo *philo, int cnt)
{
	philo->eat_cnt = 0;
	philo->order = cnt + 1;
	philo->eat = g_argu.start;
}

int				massage(int64_t time, int order, int msg)
{
	sem_wait(g_argu.msg);
	if (g_argu.death != 0)
	{
		sem_post(g_argu.msg);
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
	if (msg != FULL && msg != DIE)
		sem_post(g_argu.msg);
	return (1);
}

int				main(int argc, char *argv[])
{
	g_argu.sem = NULL;
	if (argc != 5 && argc != 6)
		return (str_error("Error: Argument!!\n", 0));
	if (!(argu_init(argc, argv)))
		return (str_error("Error: initialize error\n", 0));
	if (!(check_argu()))
		return (str_error("Error: argument error\n", 0));
	if (!(make_thread()))
		return (str_error("Error: fail to make thread\n", 0));
	clear();
	return (0);
}
