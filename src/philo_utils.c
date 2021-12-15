#include<philo.h>

void	get_time(t_info *info)
{
	struct timeval	tv;
	struct timezone	tz;
	
	int g = 0;

	(void)info;
	g = gettimeofday(&tv, &tz);
	printf("G-> %d\n", g);
}
