#include "utils.h"
#include "../philo.h"

void	wait_time(long long time)
{
	long long	cur_time;

	cur_time = time_stamp();
	while (true)
	{
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
