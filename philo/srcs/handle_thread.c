#include "philo.h"
#include "utils/utils.h"

int	join_destroy(t_info *info)
{
	int			i;
	t_philo		*philos;
	t_monitor	*monitor;

	i = 0;
	philos = info->philo;
	monitor = info->monitor;
	while (i < info->philo_num)
	{
		if (pthread_join(philos[i].philo_thread, NULL))
			return (print_message("Failed to create thread", 1));
		if (pthread_join(monitor[i].monitor_thread, NULL))
			return (print_message("Failed to create thread", 1));
		i++;
	}
	return (0);
}

int	destroy_mutex(t_info *info)
{
	int			i;

	i = 0;
	while (i < info->philo_num)
	{
		if (pthread_mutex_destroy(&info->fork[i]))
			return (print_message("pthread_mutex_destroy error", 1));
		i++;
	}
	if (pthread_mutex_destroy(&info->action))
		return (print_message("pthread_mutex_destroy error", 1));
	return (0);
}
