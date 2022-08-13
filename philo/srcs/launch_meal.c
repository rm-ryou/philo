#include "philo.h"
#include "utils/utils.h"

static void	hold_forks_(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->fork[philo->left_fork]);
	pthread_mutex_lock(&info->action);
	print_state(info, philo->id, FORK);
	pthread_mutex_unlock(&info->action);
	if (info->philo_num == 1)
		return ;
	pthread_mutex_lock(&info->fork[philo->right_fork]);
	pthread_mutex_lock(&info->action);
	print_state(info, philo->id, FORK);
	pthread_mutex_unlock(&info->action);
}

static int	meal_release_forks_(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (info->philo_num == 1)
	{
		pthread_mutex_unlock(&info->fork[philo->left_fork]);
		return (1);
	}
	pthread_mutex_lock(&info->action);
	print_state(info, philo->id, EAT);
	philo->time_last_meal = time_stamp();
	philo->meal_count++;
	pthread_mutex_unlock(&info->action);
	wait_time(info->time_eat, info);
//	pthread_mutex_lock(&info->action);
//	philo->meal_count++;
//	pthread_mutex_unlock(&info->action);
	if (info->must_eat != -1 && philo->meal_count >= info->must_eat)
	{
		pthread_mutex_unlock(&info->fork[philo->left_fork]);
		pthread_mutex_unlock(&info->fork[philo->right_fork]);
		return (1);
	}
	pthread_mutex_unlock(&info->fork[philo->left_fork]);
	pthread_mutex_unlock(&info->fork[philo->right_fork]);
	return (0);
}

void	other_actions_(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->action);
	print_state(info, philo->id, SLEEP);
	pthread_mutex_unlock(&info->action);
	wait_time(info->time_sleep, info);
	pthread_mutex_lock(&info->action);
	print_state(info, philo->id, THINK);
	pthread_mutex_unlock(&info->action);
}

void	*routine(void *philo_void)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	info = philo->info;
	wait_until_start(info);
	if (philo->id % 2 == 0)
		usleep(300);
	while (true)
	{
		hold_forks_(philo);
		if (meal_release_forks_(philo))
			return (NULL);
		other_actions_(philo);
		pthread_mutex_lock(&info->action);
		if (info->is_finished)
		{
			pthread_mutex_unlock(&info->action);
			return (NULL);
		}
		pthread_mutex_unlock(&info->action);
	}
	return (NULL);
}

int	launch_philosophers(t_info *info)
{
	int			i;
	t_philo		*philos;
	t_monitor	*monitor;

	i = 0;
	philos = info->philo;
	monitor = info->monitor;
	while (i < info->philo_num)
	{
		philos[i].time_last_meal = time_stamp();
		if (pthread_create(&philos[i].philo_thread, \
					NULL, &routine, &philos[i]))
			return (print_message("can not create pthread", 1));
		if (pthread_create(&monitor[i].monitor_thread, \
					NULL, &monitor_routine, &monitor[i]))
			return (print_message("can not create pthread", 1));
		i++;
	}
	pthread_mutex_lock(&info->action);
	info->is_start = 1;
	pthread_mutex_unlock(&info->action);
	return (0);
}
