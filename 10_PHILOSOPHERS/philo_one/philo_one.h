#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct		s_philo
{
	int				order;
	int				eat;
	int				think;
	int				sleep;
}					t_philo;

typedef struct		s_argu
{
	int				num;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	int				death;
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

#endif
