#include "philo.h"
#include "utils/utils.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5 || argc > 6)
		return (print_message(USAGE, 1));
	if (init_all(&info, argv))
		return (1);
	if (launch_philosophers(&info))
		return (1);
	if (join_destroy(&info))
		return (1);
	if (destroy_mutex(&info))
		return (1);
	return (0);
}
