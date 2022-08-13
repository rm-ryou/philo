#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include "../philo_struct.h"

int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
int			print_message(char *str, int res);
void		print_state(t_info *info, int id, char *state);
void		wait_time(long long time, t_info *info);
long long	time_stamp(void);

#endif // !UTILS_H