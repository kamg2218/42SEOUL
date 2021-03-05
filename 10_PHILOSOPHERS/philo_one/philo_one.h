#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct		s_philo
{
	int				order;
	int				eat_cnt;
	int64_t			eat;
	int64_t			start;
}					t_philo;

typedef struct		s_argu
{
	int				num;
	int64_t			die;
	int64_t			eat;
	int64_t			sleep;
	int				must_eat;
	int				death;
	int				full;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
}					t_argu;

t_argu				g_argu;

//util.c
int					ft_isspace(char c);
int					ft_atoi(const char *str);
int					ft_minus(const char *str, int *minus);
int					str_error(char *str, int re);
int					clear(void);

//philo_one.c
int					argu_init(int argc, char *argv[]);
void				philo_init(t_philo *philo);
int					make_thread(void);
void				eat_meal(t_philo *philo);
void				sleep_well(t_philo *philo);
void				think_philo(t_philo *philo);
void				*do_something(void *philo);
int64_t				get_time(void);
int64_t				get_difftime(int64_t time, int64_t start);
void				print_death(t_philo *philo);

#endif
