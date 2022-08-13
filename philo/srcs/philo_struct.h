#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_info		t_info;
typedef struct s_philo		t_philo;
typedef struct s_monitor	t_monitor;

typedef struct s_monitor
{
	int				id;
	pthread_t		monitor_thread;
	t_info			*info;
}	t_monitor;

typedef struct s_philo
{
	int				id;
	int				meal_count;
	int				right_fork;
	int				left_fork;
	long long		time_last_meal;
	pthread_t		philo_thread;
	t_info			*info;
}	t_philo;

typedef struct s_info
{
	int				philo_num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	volatile bool	is_start;
	bool			is_finished;
	pthread_mutex_t	action;
	pthread_mutex_t	fork[256];
	t_philo			philo[256];
	t_monitor		monitor[256];
}	t_info;

#endif // !PHILO_STRUCT_H
