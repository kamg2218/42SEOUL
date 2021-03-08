#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

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

//util.c
int					ft_atoi(const char *str);
int					ft_minus(const char *str, int *minus);
int					str_error(char *str, int re);
int					clear(void);
int64_t				get_time(void);

//philo_one.c
int					argu_init(int argc, char *argv[]);
void				philo_init(t_philo *philo, int cnt);
void				*monitor(void *philo);
int					massage(int64_t time, int order, int msg);

//philo_work.c
int					make_thread(void);
void				eat_meal(t_philo *philo);
void				sleep_well(t_philo *philo);
void				*routine(void *philo);

#endif
