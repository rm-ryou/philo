#include "utils.h"
#include "../philo.h"

void	wait_time(long long time, t_info *info)
{
	long long	cur_time;

	cur_time = time_stamp();
//	while (!info->is_finished)
	while (true)
	{
	/*	pthread_mutex_lock(&info->action);
		if (info->is_finished)
		{
			pthread_mutex_unlock(&info->action);
			return ;
		}
		pthread_mutex_unlock(&info->action);*/
		if (time_stamp() - cur_time >= time)
			break ;
		usleep(50);
	}
}

long long	time_stamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
