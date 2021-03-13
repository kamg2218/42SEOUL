/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:40:29 by hyoon             #+#    #+#             */
/*   Updated: 2021/03/13 19:50:59 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
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
	t_philo			*philo;
	pthread_t		*thread;
	sem_t			*sem;
	sem_t			*msg;
}					t_argu;

t_argu				g_argu;

int					ft_atoi(const char *str);
int					ft_minus(const char *str, int *minus);
int					str_error(char *str, int re);
int					clear(void);
int64_t				get_time(void);

int					argu_init(int argc, char *argv[]);
void				philo_init(t_philo *philo, int cnt);
void				*monitor(void *philo);
int					massage(int64_t time, int order, int msg);
int					check_argu(void);

int					check_argu(void);
int					make_thread(void);
void				eat_meal(t_philo *philo);
void				sleep_well(t_philo *philo);
void				*routine(void *philo);

#endif
