#include<philo.h>

long	get_time(void)
{
	struct timeval	tv;
	struct timezone	tz;
	long			time;
	
	gettimeofday(&tv, &tz);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	first_data(t_info *info)
{
	info->n_forks = info->nbrs[0];
	info->t_die = info->nbrs[1];
	info->t_eat = info->nbrs[2];
	info->t_sleep = info ->nbrs[3];
	if (info->argc == 5)
		info->must_eat = info->nbrs[4];
	else
		info->must_eat = 0;
	info->time = get_time();
}

void	show_info(t_info *info)
{
	int	i;

	i = 0;
	printf("\tINFO\n");
	printf("Argc: %d\n", info->argc);
	while (info->nbrs[i])
	{
		printf("Nbr[%d]: %d\t", i, info->nbrs[i]);
		i++;
	}
	printf("\nNum philos/forks: %d\n", info->n_forks);
	printf("Die: %d\t Eat: %d\t Sleep: %d\t Must eat: %d\n", 
		info->t_die, info->t_eat, info->t_sleep, info->must_eat);
	printf("Time: %ld\n", info->time);
}
