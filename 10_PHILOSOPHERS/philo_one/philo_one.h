/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:33:47 by hyoon             #+#    #+#             */
/*   Updated: 2021/03/11 20:49:37 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4
# define FORK 5
# define FULL 6

typedef struct		s_philo
{
	int				order;
	int				eat_cnt;
	int				right;
	int64_t			eat;
	pthread_t		monitor;
}					t_philo;

typedef struct		s_argu
{
	int				num;
	int64_t			die;
	int64_t			eat;
	int64_t			sleep;
	int64_t			start;
	int				must_eat;
	int				death;
	int				full;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	msg;
}					t_argu;

t_argu				g_argu;

int					clear(void);
int					ft_atoi(const char *str);
int					str_error(char *str, int re);
int					ft_minus(const char *str, int *minus);
int64_t				get_time(void);

int					check_argu(void);
int					argu_init(int argc, char *argv[]);
int					massage(int64_t time, int order, int msg);
void				philo_init(t_philo *philo, int cnt);

int					make_thread(void);
void				eat_meal(t_philo *philo);
void				sleep_well(t_philo *philo);
void				*routine(void *philo);
void				*monitor(void *philo);

#endif
