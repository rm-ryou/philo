#include "philo.h"
#include "utils/utils.h"

static int	is_dead_(t_monitor *monitor, int i)
{
	t_info	*info;
	t_philo	*philo;

	info = monitor->info;
	philo = info->philo;
	pthread_mutex_lock(&info->action);
	if (info->must_eat != -1 && philo[i].meal_count >= info->must_eat)
	{
		pthread_mutex_unlock(&info->action);
		return (1);
	}
	pthread_mutex_unlock(&info->action);
	pthread_mutex_lock(&info->action);
	if (!info->is_finished && time_stamp() - philo[i].time_last_meal > info->time_die)
	{
		print_state(info, i, DIED);
		info->is_finished = true;
		pthread_mutex_unlock(&info->action);
		return (1);
	}
	pthread_mutex_unlock(&info->action);
	return (0);
}

void	wait_until_start(t_info *info)
{
	while (true)
	{
		pthread_mutex_lock(&info->action);
		if (info->is_start)
		{
			pthread_mutex_unlock(&info->action);
			return ;
		}
		pthread_mutex_unlock(&info->action);
		usleep(50);
	}
}

void	*monitor_routine(void *monitor_void)
{
	int			i;
	t_info		*info;
	t_monitor	*monitor;

	monitor = (t_monitor *)monitor_void;
	info = monitor->info;
	i = monitor->id;
	wait_until_start(info);
	while (true)
	{
		if (is_dead_(monitor, i))
			return (NULL);
		pthread_mutex_lock(&info->action);
		if (info->is_finished)
		{
			pthread_mutex_unlock(&info->action);
			return (NULL);
		}
		pthread_mutex_unlock(&info->action);
		usleep(100);
	}
	return (NULL);
}
