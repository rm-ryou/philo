#include "philo.h"
#include "utils/utils.h"

static int	is_num_(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_is_num_(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_num_(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_args(char **argv)
{
	if (check_is_num_(argv))
		return (1);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (1);
	if (ft_atoi(argv[2]) <= 60)
		return (1);
	if (ft_atoi(argv[3]) <= 60)
		return (1);
	if (ft_atoi(argv[4]) <= 60)
		return (1);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) < 1)
			return (1);
	}
	return (0);
}
