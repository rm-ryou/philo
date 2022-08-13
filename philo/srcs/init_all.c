#include "philo.h"
#include "utils/utils.h"

static int	is_valid_args_(char **argv)
{
	int	flg;

	flg = 0;
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		flg = 1;
	if (ft_atoi(argv[2]) <= 60)
		flg = 1;
	if (ft_atoi(argv[3]) <= 60)
		flg = 1;
	if (ft_atoi(argv[4]) <= 60)
		flg = 1;
	if (argv[5])
	{
		if (ft_atoi(argv[5]) < 1)
			flg = 1;
	}
	return (flg);
}

static void	set_args_(t_info *info, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = -1;
	info->is_start = false;
	info->is_finished = false;
}

static int	init_philos_(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		info->philo[i].id = i;
		info->philo[i].meal_count = 0;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % info->philo_num;
		info->philo[i].time_last_meal = 0;
		info->philo[i].info = info;
		i++;
	}
	return (0);
}

static int	init_monitor_(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		info->monitor[i].id = i;
		info->monitor[i].info = info;
		i++;
	}
	return (0);
}

int	init_all(t_info *info, char **argv)
{
	int	i;

	if (is_valid_args_(argv))
		return (print_message("invalid argument", 1));
	set_args_(info, argv);
	if (init_philos_(info))
		return (1);
	if (init_monitor_(info))
		return (1);
	if (pthread_mutex_init(&info->action, NULL))
		return (print_message("mutex_init error", 1));
	i = 0;
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (print_message("mutex_init error", 1));
		i++;
	}
	return (0);
}
