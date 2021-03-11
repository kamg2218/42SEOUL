/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:32:04 by hyoon             #+#    #+#             */
/*   Updated: 2021/03/11 20:33:19 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/types.h>

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
	pid_t			*pid;
	sem_t			*sem;
	sem_t			*msg;
	sem_t			*monitor;
	sem_t			*full;
}					t_argu;

t_argu				g_argu;

int					ft_atoi(const char *str);
int					ft_minus(const char *str, int *minus);
int					str_error(char *str, int re);
int64_t				get_time(void);

void				*get_full(void *philo);
void				*get_death(void *philo);
void				*monitor(void *philo);

int					check_argu(void);
int					argu_init(int argc, char *argv[]);
void				philo_init(t_philo *philo, int cnt);
int					massage(int64_t time, int order, int msg);

int					make_thread(void);
int					make_monitor(void);
void				eat_meal(t_philo *philo);
void				sleep_well(t_philo *philo);
void				*routine(t_philo *philo);

#endif
