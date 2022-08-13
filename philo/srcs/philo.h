#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include "philo_struct.h"

# define USAGE	"\x1b[31m[usage]\x1b[39m: ./philo \
	[num_philo] [die_time] [eat_time] [sleep_time] ([must_eat_time])"
# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DIED	"died"

// in init_all.c
int		init_all(t_info *info, char **argv);

// in launch_meal.c
int		launch_philosophers(t_info *info);

// in monitor.c
void	wait_until_start(t_info *info);
void	*monitor_routine(void *monitor_void);

// in handle_thread.c
int		destroy_mutex(t_info *info);
int		join_destroy(t_info *info);


#endif // !PHILO_H