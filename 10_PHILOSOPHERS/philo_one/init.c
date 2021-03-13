/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:34:09 by hyoon             #+#    #+#             */
/*   Updated: 2021/03/13 20:40:46 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
	if (!check_argu())
		return (0);
	return (1);
}

int				pointer_init(void)
{
	int			cnt;

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
	philo->right = 0;
	if (philo->right < g_argu.num)
		philo->right = cnt + 1;
	philo->eat = g_argu.start;
}
