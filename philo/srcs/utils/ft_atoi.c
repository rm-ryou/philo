#include "utils.h"

static int	ft_isspace_(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static long	launch_a2i_(const char *nptr, int *overflow)
{
	unsigned char	c;
	long			res;
	long			cutoff;
	long			cutlim;

	res = 0;
	cutoff = LONG_MAX / 10;
	cutlim = LONG_MIN % 10;
	while (ft_isdigit(*nptr))
	{
		c = *nptr - '0';
		if (res > cutoff || (res == cutoff && c > cutlim))
			*overflow = 1;
		res = res * 10 + c;
		nptr++;
	}
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int		negative;
	int		overflow;
	long	res;

	negative = 1;
	overflow = 0;
	while (ft_isspace_(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			negative = -1;
		nptr++;
	}
	res = launch_a2i_(nptr, &overflow);
	if (overflow && negative == 1)
		return ((int)LONG_MAX);
	else if (overflow && negative == -1)
		return ((int)LONG_MIN);
	return ((int)res * negative);
}
