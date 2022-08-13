#include "utils.h"
#include "../philo.h"

int	print_message(char *str, int res)
{
	printf("%s\n", str);
	return (res);
}

void	print_state(t_info *info, int id, char *state)
{
	if (!info->is_finished)
	{
		printf("%5lli ", time_stamp());
		printf("%d %s\n", id + 1, state);
	}
}
